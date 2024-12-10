#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Jefe.h"

    /*Jefe::Jefe(){
        j_texture.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
        j_sprite.setTexture(j_texture);
        j_sprite.setTextureRect({0,0,130,130});
        j_sprite.setOrigin(j_sprite.getGlobalBounds().width/2,j_sprite.getGlobalBounds().height);
        j_hitbox.setSize({50,40});
        j_hitbox.setFillColor(sf::Color::Magenta);
        j_sprite.setPosition(1050,250);
        j_vida=500;
    }
*/

    Jefe::Jefe(){
        _textureE.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
        e_sprite.setTexture(_textureE);
        e_sprite.setTextureRect({0,0,130,130});
        e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
        en_hitbox.setSize({55,90});
        en_hitbox.setFillColor(sf::Color::Yellow);
        e_vida=100;
        attackHitbox.setSize({25,-60});
        attackHitbox.setFillColor(sf::Color::Red);
        damageHitbox.setSize({25,-50});
        damageHitbox.setFillColor(sf::Color::Black);
        damage=50;
    }
    void Jefe::attackFrames(){
            _frame2 += 0.30;
            if (e_sprite.getScale().x == -1 && _frame2 > 2) {
                en_hitbox.setPosition(e_sprite.getGlobalBounds().left + 40, e_sprite.getGlobalBounds().top + 60);
            } else if (_frame2 > 2) {
                en_hitbox.setPosition(en_hitbox.getGlobalBounds().left + 55, e_sprite.getGlobalBounds().top + 60);
                damageFlag=true;
            }
            e_velocity = {0, 0};
            e_sprite.setTextureRect({0 + (int)_frame2 * 130, 390, 130, 130});
            if(_frame2>=13){
                _frame2=0;
                countdown=20;
                damageFlag=false;
            }
        }


    void Jefe::update(pj ejemplo){
        e_velocity= {};

        if(e_velocity.x==0&&e_velocity.y==0){
            _frame+=0.009;
            e_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
            if(_frame>=4){
                _frame=0;
            }
        }

        if(e_velocity.x==0&&e_velocity.y==0 ){
            _frame+=0.2;
            e_velocity.x=-2 * _direccion;
            e_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
            if(_frame>=6){
                _frame=0;
            }
        }

         if(en_hitbox.getGlobalBounds().left< limitA){
        e_sprite.setPosition(e_sprite.getPosition().x + 4, e_sprite.getPosition().y);
        en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        _direccion=_direccion*-1;
    }

    if (en_hitbox.getGlobalBounds().left + en_hitbox.getGlobalBounds().width> limitB){
        e_sprite.setPosition(limitB - (e_sprite.getGlobalBounds().width - 350), e_sprite.getPosition().y);
        en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        _direccion=_direccion*-1;
    }

        if(e_velocity.x< 0){
            e_sprite.setScale(-3,3);//setScale es el encargado del efecto visual para que el personaje se de vuelta
            attackHitbox.setPosition(e_sprite.getGlobalBounds().left+140,e_sprite.getGlobalBounds().top+220);
            damageHitbox.setPosition(e_sprite.getGlobalBounds().left+120,e_sprite.getGlobalBounds().top+220);
        } else if(e_velocity.x> 0 ){
            e_sprite.setScale(3,3);
            attackHitbox.setPosition(e_sprite.getGlobalBounds().left+230,e_sprite.getGlobalBounds().top+220);
            damageHitbox.setPosition(e_sprite.getGlobalBounds().left+220,e_sprite.getGlobalBounds().top+220);
        }

        if (countdown >= 0){
                attack=false;
                _frame2 = 0;
                countdown-=0.1;
        }

        if(attackHitbox.getGlobalBounds().intersects(ejemplo.getHitbox().getGlobalBounds())&&countdown<=0){
            attack=true;
        }

        if(attack==true){
            attackFrames();
        }
        e_sprite.move(e_velocity);


        sf::Vector2f spritePos = e_sprite.getPosition();
        float centerX = spritePos.x + e_sprite.getGlobalBounds().width / 3.f;
        float centerY = spritePos.y + e_sprite.getGlobalBounds().height / 3.f;
        // Position en_hitbox based on the sprite's scaled size and its center
        en_hitbox.setPosition(centerX - 160, centerY - 400);
    }
/*    void Jefe::update(mapa& _objetoMapa, pj ejemplo){

    j_velocity={};

        if(j_velocity.x==0&& j_velocity.y==0){
            _frame+=0.009;
            j_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
            if(_frame>=4){
                _frame=0;
            }
        }

        if(j_velocity.x==0&&j_velocity.y==0 ){
                _frame+=0.2;
                j_velocity.x=-2 * _direccion;
                j_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
                if(_frame>=6){
                _frame=0;
                }
            }

        if(j_velocity.x<0){
            j_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
            }
            else if(j_velocity.x > 0 ){
                j_sprite.setScale(1,1);
            }

    // Verificar colisiones en el eje X
    // j_hitbox.setPosition(j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);
        if (_objetoMapa.verificarColision(j_hitbox)) {

            _direccion = -1; // Cambiar dirección hacia la derecha
            j_sprite.setPosition(j_sprite.getPosition().x + 4, j_sprite.getPosition().y);
            j_hitbox.setPosition(j_hitbox.getPosition().x - j_velocity.x, j_hitbox.getPosition().y);
        }

        if (j_hitbox.getGlobalBounds().left < 0) {

            _direccion = -1; // Cambiar dirección hacia la derecha
            j_sprite.setPosition(j_sprite.getPosition().x + 4, j_sprite.getPosition().y);
            j_hitbox.setPosition(j_hitbox.getPosition().x - j_velocity.x, j_hitbox.getPosition().y);
        }

        if (j_hitbox.getGlobalBounds().left+50 > 1600) {

            _direccion = 1; // Cambiar dirección hacia la izquierda
            j_sprite.setPosition(j_sprite.getPosition().x - 4, j_sprite.getPosition().y);
            j_hitbox.setPosition(j_hitbox.getPosition().x - j_velocity.x, j_hitbox.getPosition().y);
        }

        if (countdown >= 0) {

                attack=false;
                _frame2 = 0;
                countdown-=0.1;
            }

        if(j_hitbox.getGlobalBounds().intersects(ejemplo.getHitbox().getGlobalBounds())&&countdown<=0){

            attack=true;
        }

        if(attack==true){
            _frame2 += 0.30;
            if (j_sprite.getScale().x == -1 && _frame2 > 2) {
                j_hitbox.setPosition(j_sprite.getGlobalBounds().left + 40, j_sprite.getGlobalBounds().top + 60);
            } else if (_frame2 > 2) {
                j_hitbox.setPosition(j_hitbox.getGlobalBounds().left + 55, j_sprite.getGlobalBounds().top + 60);
            }
            j_velocity = {0, 0};
            j_sprite.setTextureRect({0 + (int)_frame2 * 130, 390, 130, 130});
            if(_frame2>=13){
                _frame2=0;
                countdown=20;
            }
        }

        j_sprite.move(j_velocity);
        j_hitbox.setPosition(j_sprite.getPosition().x - 30,j_sprite.getPosition().y - j_sprite.getGlobalBounds().height + 30);
    }


    bool Jefe::isAlive(){
    if(j_vida > 0  ) return true;
    else return false;
    }

    void Jefe::setSpritePosition(float x,float y){
        j_sprite.setPosition(x,y);
    }

    void Jefe::danioRecivido(int danio){

        j_vida=j_vida-danio;

    }

    void Jefe::ataque(){

        _frame2+=0.01;
        j_velocity.x=0;
        //j_velocity.x=-2 * _direccion;
        j_sprite.setTextureRect({130 + (int)_frame*130,520,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame2>=13){
            _frame2=0;
        }

    }

    void Jefe::draw(sf::RenderTarget& target, sf::RenderStates states) const{

        //  `j_sprite` es el sprite principal del jefe
        target.draw(j_hitbox);
        target.draw(j_sprite, states);
    }

    sf::RectangleShape Jefe::getHitbox()const{

        return j_hitbox;

    }
    */


//Jefe::~Jefe()
//{
//    //dtor
//}
