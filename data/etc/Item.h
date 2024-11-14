#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#include "colisionable.h"
#include "inc.h"

class Item: public sf::Drawable, public colisionable
{
    public:
        void update();//Metodo para actualizar la posicion del personaje
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;//Dibuja al personaje
        void respawn(mapa& _objetoMapa);
//        sf::FloatRect getBounds()const override;
        sf::RectangleShape getHitbox()const override;
        Item();
        bool getActive();
        void setActive(bool e);
    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _textureM;
        sf::RectangleShape m_hitbox;
        bool activo=false;
};

#endif // ITEM_H
