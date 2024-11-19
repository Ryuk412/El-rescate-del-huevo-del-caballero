#ifndef ENEMIGOBASE_H_INCLUDED
#define ENEMIGOBASE_H_INCLUDED
#include "inc.h"
#include "pj.h"
class enemigoBase:public sf::Drawable{
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

        float _frame=0;
        float _frame2=0;
        float _frame3=0;
        float countdown=0;

        bool attack=false;
        bool damageFlag=false;

    public:
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        void update(pj ejemplo);
        void setSpritePosition(int posX, int posY, int posA, int posB);
        void muerte();
        void respawn();
        bool isAlive();
        void danioRecibido(int danio);
        virtual void attackFrames();
        float getVelocityX();

};

#endif // ENEMIGOBASE_H_INCLUDED
