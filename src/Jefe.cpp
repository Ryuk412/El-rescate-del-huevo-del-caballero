#include <iostream>
#include <cstdlib>
#include <stdio.h>
Jefe::Jefe()
{

    j_texture.loadFromFile("assets\Characters(100x100)\Knight Templar\Knight Templar.png");
   j_sprite.setTexture(j_texture);
    j_sprite.setTextureRect({0,0,130,130});
    j_sprite.setOrigin(j_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
    j_hitbox.setSize({60,30});
    j_hitbox.setFillColor(sf::Color::Magenta);
    j_sprite.setPosition(350,255);
    j_vida=500;

}
void Jefe::update(){














}
//Jefe::~Jefe()
//{
//    //dtor
//}
