#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <cstdlib>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "colisionable.h"
#include <stdlib.h>
#include <iostream>

class enemigo:  public sf::Drawable, public colisionable
{
    public:

        enemigo();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
    sf::RectangleShape getHitbox()const override;

    private:


        sf::RectangleShape en_hitbox;
        sf::Sprite e_sprite;
        sf::Texture _textureE;
        sf::Vector2f e_velocity={};
         float _frame=0;
};

#endif // ENEMIGO_H
