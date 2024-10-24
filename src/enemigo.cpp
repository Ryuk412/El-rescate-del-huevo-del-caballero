#include <iostream>


#include "enemigo.h"

enemigo::enemigo()
{

_textureE.loadFromFile("assets/Characters(100x100)/Slime/Slime/Slime.png");
e_sprite.setTexture(_textureE);
e_sprite.setTextureRect({0,0,130,130});
e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
en_hitbox.setSize({60,30});
en_hitbox.setFillColor(sf::Color::Yellow);
e_sprite.setPosition(200,255);



}
void enemigo::update(){

e_velocity={};

 if(e_velocity.x==0&&e_velocity.y==0){
            _frame+=0.09;
            e_sprite.setTextureRect({0 + (int)_frame*130 ,0,130,130});//Ancho y Alto del Personaje,70x65.
            if(_frame>=6){
                _frame=0;
            }
        }
if(e_velocity.x==0&&e_velocity.y==0){


       _frame+=0.2;
                e_velocity.x=+2;
                e_sprite.setTextureRect({130 + (int)_frame*130 ,130,130,130});//Ancho y Alto del Personaje,70x65.
                if(_frame>=6){
                _frame=0;
                }
}
 e_sprite.move(e_velocity);


            if(e_velocity.x < 0){
            e_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
        }else if(e_velocity.x > 0 ){
            e_sprite.setScale(1,1);
        }


       en_hitbox.setPosition( e_sprite.getGlobalBounds().left + 30 , e_sprite.getGlobalBounds().top + 50 );



        if(en_hitbox.getGlobalBounds().left + en_hitbox.getGlobalBounds().width > 800){
           e_sprite.setPosition(800 - (e_sprite.getGlobalBounds().width - 170),  e_sprite.getPosition().y);
            en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
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
