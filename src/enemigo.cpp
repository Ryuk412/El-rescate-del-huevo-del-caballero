#include <iostream>


#include "enemigo.h"

enemigo::enemigo()
{

_textureE.loadFromFile("assets/Characters(100x100)/Slime/Slime/Slime.png");
e_sprite.setTexture(_textureE);
e_sprite.setTextureRect({0,0,130,130});
e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
en_hitbox.setSize({30,60});
en_hitbox.setFillColor(sf::Color::Yellow);
e_sprite.setPosition(200,300);



}
 void enemigo::update(){

          //Cada vez que se actualiza el personaje, obtiene velocidad 0 en x y 0 en y

        e_velocity={0,0};

        if(e_velocity.x==0 && e_velocity.y==0){
            _frame+=0.09;
            e_sprite.setTextureRect({0 + (int)_frame*130 ,0,130,130});//Ancho y Alto del Personaje,70x65.
            if(_frame>=5){
                _frame=0;
            }
        }
        //Si se presiona una tecla, la velocidad cambia a 4 o -4, dependiendo la dirección,
        //Por lo que antes de dibujar el personaje se va a mover de su posicion anterior
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){

                _frame+=0.2;
                e_velocity.y=-4;
                e_sprite.setTextureRect({130 + (int)_frame*130 ,130,130,130});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                _frame+=0.2;
                e_velocity.x=-4;
                e_sprite.setTextureRect({130 + (int)_frame*130 ,130,130,130});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                _frame+=0.2;
                e_velocity.y=4;
                    e_sprite.setTextureRect({130 + (int)_frame*130 ,130,130,130});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                _frame+=0.2;
                e_velocity.x=4;
                e_sprite.setTextureRect({130 + (int)_frame*130 ,130,130,130});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }

 e_sprite.move(e_velocity);
        //Estas dos condicionales lo que hacen es verificar si el personaje se esta moviendo
        //Hacia la derecha o hacia la izquierda, para que el sprite mire hacia la misma direccion
        if(e_velocity.x < 0){
            e_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
        }else if(e_velocity.x > 0 ){
             e_sprite.setScale(1,1);
        }

        en_hitbox.setPosition(5+ e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);

        //Condicionales para mantener al personaje dentro de la ventana y que no pueda salir
        if(en_hitbox.getGlobalBounds().left < 0){
            e_sprite.setPosition(e_sprite.getPosition().x+4, e_sprite.getPosition().y);
           en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        }
//M_HITBOX es una propiedad de la clase pj que se encarga de general el cuadrado de la hiybox (xd)

        if(en_hitbox.getGlobalBounds().top < 0){
            e_sprite.setPosition(e_sprite.getPosition().x,e_sprite.getPosition().y+4);
           en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        }


        if(en_hitbox.getGlobalBounds().left + en_hitbox.getGlobalBounds().width > 800){
            e_sprite.setPosition(800 - (e_sprite.getGlobalBounds().width - 170),  e_sprite.getPosition().y);
            en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        }


        if(en_hitbox.getGlobalBounds().top + en_hitbox.getGlobalBounds().height > 600){
            e_sprite.setPosition(e_sprite.getPosition().x, 600 + (e_sprite.getGlobalBounds().height - 122));
           en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        }
        }
 }



 void enemigo::draw(sf::RenderTarget& target, sf::RenderStates state)const{
    target.draw(en_hitbox);
    target.draw(e_sprite);
 }
//
//enemigo::~enemigo()
//{
//    //dtor
//}
