#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Jefe.h"
Jefe::Jefe()
{


    j_texture.loadFromFile("assets/Characters(100x100)/Wizard/Wizard/Wizard.png");
    j_sprite.setTexture(j_texture);
    j_sprite.setTextureRect({0,0,130,130});
    j_sprite.setOrigin(j_sprite.getGlobalBounds().width/2,j_sprite.getGlobalBounds().height);
    j_hitbox.setSize({60,30});
    j_hitbox.setFillColor(sf::Color::Magenta);
    j_sprite.setPosition(350,200);
    j_vida=500;

}
void Jefe::update(){














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
    target.draw(j_sprite, states);
    target.draw(j_hitbox);
}

//Jefe::~Jefe()
//{
//    //dtor
//}
