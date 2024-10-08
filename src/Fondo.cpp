#include<iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Fondo.h"

Fondo::Fondo(){

_textureF.loadFromFile("data/images/Fondo");
_spriteF.setTexture(_textureF);

}
void Fondo::draw(sf::RenderTarget& target, sf::RenderStates state)const {
        target.draw(_sprite, state);
}
