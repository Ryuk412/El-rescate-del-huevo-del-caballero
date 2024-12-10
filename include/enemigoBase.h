#ifndef ENEMIGOBASE_H_INCLUDED
#define ENEMIGOBASE_H_INCLUDED
#include "inc.h"
#include "pj.h"
class enemigoBase:public sf::Drawable,public colisionable{
    protected:
        sf::Sprite e_sprite;
        sf::Texture _textureE;
        sf::Vector2f e_velocity={};

        sf::RectangleShape en_hitbox;
        sf::RectangleShape attackHitbox;
        sf::RectangleShape damageHitbox;

        int _direccion=-1;
        int e_vida;
        int startInX;
        int startInY;
        int limitA;
        int limitB;
        int damage;

        float _frame=0;
        float _frame2=0;
        float _frame3=0;
        float countdown=0;

        bool attack=false;
        bool damageFlag=false;

    public:
        sf::RectangleShape getDamageHitbox();
        sf::RectangleShape getHitbox()const override;

        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        virtual void update(pj ejemplo);
        void setSpritePosition(int posX, int posY, int posA, int posB);
        void muerte();
        void respawn();
        void danioRecibido(int danio);
        virtual void attackFrames();

        int getDamage();
        int getVida();

        float getVelocityX();

        bool isAlive();

};

#endif // ENEMIGOBASE_H_INCLUDED
