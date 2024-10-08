#ifndef FONDO_H
#define FONDO_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include <stdlib.h>

class Fondo
{
    public:

        Fondo();
void update();
void draw(sf::RenderTarget& target, sf::RenderStates state)const;

          private:
        sf::Sprite _spriteF;
        sf::Texture _textureF;
};

#endif // FONDO_H
