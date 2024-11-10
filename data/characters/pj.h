#ifndef PJ_H
#define PJ_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "colisionable.h"
#include "inc.h"

class pj: public sf::Drawable, public colisionable
{
    public:

        void update(mapa& _objetoMapa);
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
//        sf::FloatRect getBounds()const override;
        sf::RectangleShape getHitbox()const override;
        sf::RectangleShape getHitboxE();
        void setColisionando(bool estado);
        pj();
        bool getBan();
        void respawn();
        virtual ~pj();
        void muerte();
        bool isAlive();
        void danioRecibido(int danio);
        void curar(int cant);
        float getPositionX();
        float getPositionY();
    protected:

    private:
        bool _ban=false;
        sf::RectangleShape e_hitbox;
        sf::RectangleShape m_hitbox;
        sf::RectangleShape _bVida;
        sf::Sprite _sprite;
        sf::Texture _textureM;
        float _gravity=1.0f;
        float _jumpVelocity = -20.0f;
        bool _isJumping = false;
        bool _colisiionando=false;
        sf::Vector2f _velocity={};
        float _frame=0;
        float _frame2=0;
        float _frame3=0;
        float _frame4=0;
        float _frame5=0;
        float _vida;
};

#endif // PJ_H
