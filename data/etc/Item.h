#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class Item: public sf::Drawable, public colisionable
{
    public:
        void update();//Metodo para actualizar la posicion del personaje
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;//Dibuja al personaje
        void respawn();
        sf::FloatRect getBounds()const override;
        Item();

    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _textureM;
};

#endif // ITEM_H
