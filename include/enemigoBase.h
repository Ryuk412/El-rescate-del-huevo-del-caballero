#ifndef ENEMIGOBASE_H_INCLUDED
#define ENEMIGOBASE_H_INCLUDED
#include "inc.h"
#include "pj.h"
class enemigoBase{
    private:
    protected:
        sf::RectangleShape en_hitbox;
        sf::RectangleShape attackHitbox;
        int _direccion=-1;
        sf::Sprite e_sprite;
        sf::Texture _textureE;
        sf::Vector2f e_velocity={};
        float _frame=0;
        float _frame2=0;
        float _frame3=0;
        int e_vida;
        int limitA;
        int limitB;
        float countdown=0;
        bool attack=false;
    public:
        void muerte();
        void respawn();
        bool isAlive();
        void danioRecibido(int danio);
        void setSpritePosition(int posX, int posY, int posA, int posB);
        void update(pj ejemplo);
        virtual void attackFrames();

};

#endif // ENEMIGOBASE_H_INCLUDED
