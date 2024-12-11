#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Jefe.h"

    Jefe::Jefe(){
        _textureE.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
        e_sprite.setTexture(_textureE);
        e_sprite.setTextureRect({0,0,130,130});
        e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
        en_hitbox.setSize({55,90});
        en_hitbox.setFillColor(sf::Color::Transparent);
        e_vida=100;
        attackHitbox.setSize({25,-60});
        attackHitbox.setFillColor(sf::Color::Transparent);
        damageHitbox.setSize({25,-50});
        damageHitbox.setFillColor(sf::Color::Transparent);
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
        //Jefe necesita su update propio, ya que usar el setScale altera todos los parámetros de las hitboxes y los límites.
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
            e_sprite.setScale(-3,3);
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

        //Esto ayuda a posicionar a en_hitbox ahora que getGlobalBounds fue alterado por setScale
        sf::Vector2f spritePos = e_sprite.getPosition();
        float centerX = spritePos.x + e_sprite.getGlobalBounds().width / 3.f;
        float centerY = spritePos.y + e_sprite.getGlobalBounds().height / 3.f;

        en_hitbox.setPosition(centerX - 160, centerY - 400);
    }

//Jefe::~Jefe()
//{
//    //dtor
//}
