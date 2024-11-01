#ifndef PJ_H
#define PJ_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "colisionable.h"
#include "inc.h"

class pj: public sf::Drawable, public colisionable
//Si una clase se va a mostrar en pantalla, se debe heredar el metodo DRAW de la clase Drawable
{
    public:

        void update();//Metodo para actualizar la posicion del personaje
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;//Dibuja al personaje
//        sf::FloatRect getBounds()const override;
        sf::RectangleShape getHitbox()const override;
        sf::RectangleShape getHitboxE();
        void setColisionando(bool estado);
        pj();
        bool getBan();
        void respawn();
        virtual ~pj();
        void addGravity(float f);
        void isGravity(pj pj,sf::RectangleShape obj);
        void setGravity(bool e);
    protected:

    private:
        bool gravity=false;
        bool _ban=false;
        sf::RectangleShape e_hitbox;
        sf::RectangleShape m_hitbox;
        sf::Sprite _sprite;
        sf::Texture _textureM;
        bool _colisiionando=false;
        sf::Vector2f _velocity={};//Vector de 2 posiciones que define la velocidad en pixeles que tiene el personaje en X e Y
        float _frame=0;
        float _frame2=0;

};

#endif // PJ_H
