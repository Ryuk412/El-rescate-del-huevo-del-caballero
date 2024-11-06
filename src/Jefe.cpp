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
    j_sprite.setPosition(900,250);
    j_vida=500;

}
void Jefe::update(int limitA, int limitB){





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

    if(j_hitbox.getGlobalBounds().left < 0   )
    {

        j_sprite.setPosition(j_sprite.getPosition().x + 4, j_sprite.getPosition().y);
        j_hitbox.setPosition(5 + j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (j_hitbox.getGlobalBounds().left + j_hitbox.getGlobalBounds().width > 800)
    {
        j_sprite.setPosition(800 - (j_sprite.getGlobalBounds().width - 103),j_sprite.getPosition().y);
        j_hitbox.setPosition(5 + j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;

    }


    if(j_velocity.x < 0)
    {
       j_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(j_velocity.x > 0 )
    {
        j_sprite.setScale(1,1);
    }



     if(j_hitbox.getGlobalBounds().left < limitA)
    {

        j_sprite.setPosition(j_sprite.getPosition().x + 4, j_sprite.getPosition().y);
        j_hitbox.setPosition(5 + j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (j_hitbox.getGlobalBounds().left + j_hitbox.getGlobalBounds().width > limitB)
    {
        j_sprite.setPosition(limitB - (j_sprite.getGlobalBounds().width - 103), j_sprite.getPosition().y);
        j_hitbox.setPosition(5 + j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;
    }


    j_sprite.move(j_velocity);

    j_hitbox.setPosition(j_sprite.getGlobalBounds().left + 30, j_sprite.getGlobalBounds().top + 30 );

}


bool Jefe::isAlive(){
if(j_vida > 0  ){ return true;   }
 else{return false;    }


}

void Jefe::danioRecivido(int danio){

j_vida=j_vida-danio;

}
void Jefe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //  `j_sprite` es el sprite principal del jefe
    target.draw(j_hitbox);
    target.draw(j_sprite, states);
}

//Jefe::~Jefe()
//{
//    //dtor
//}
