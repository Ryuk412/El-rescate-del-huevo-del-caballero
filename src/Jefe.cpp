#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Jefe.h"
Jefe::Jefe()
{


    j_texture.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
    j_sprite.setTexture(j_texture);
    j_sprite.setTextureRect({0,0,130,130});
    j_sprite.setOrigin(j_sprite.getGlobalBounds().width,j_sprite.getGlobalBounds().height);
    j_hitbox.setSize({60,30});
    j_hitbox.setFillColor(sf::Color::Magenta);
    j_sprite.setPosition(1050,250);
    j_vida=500;


}
void Jefe::update(mapa& _objetoMapa){

j_velocity={};

if(j_velocity.x==0&& j_velocity.y==0)
    {
        _frame+=0.009;
        j_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4)
        {
            _frame=0;
        }
    }

    if(j_velocity.x==0&&j_velocity.y==0 )
    {



        _frame+=0.2;
        j_velocity.x=-2 * _direccion;
        j_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }






    if(j_velocity.x < 0)
    {
       j_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(j_velocity.x > 0 )
    {
        j_sprite.setScale(1,1);
    }



//  // Verificar si el objeto ha llegado a los límites y cambiar la dirección suavemente
//if (j_hitbox.getGlobalBounds().left <= LimiteA) {

//} else if (j_hitbox.getGlobalBounds().left + j_hitbox.getGlobalBounds().width >= LimiteB) {
//
//}
    j_sprite.move(j_velocity);

    j_hitbox.setPosition(j_sprite.getGlobalBounds().left + 30, j_sprite.getGlobalBounds().top + 30 );



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
}


bool Jefe::isAlive(){
if(j_vida > 0  ){ return true;   }
 else{return false;    }

}
void Jefe::setSpritePosition(float x,float y){
    j_sprite.setPosition(x,y);
}
void Jefe::danioRecivido(int danio){

j_vida=j_vida-danio;

}
void Jefe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //  `j_sprite` es el sprite principal del jefe
    target.draw(j_hitbox);
    target.draw(j_sprite, states);
}

sf::RectangleShape Jefe::getHitbox()const
{
    return j_hitbox;
}
//Jefe::~Jefe()
//{
//    //dtor
//}
