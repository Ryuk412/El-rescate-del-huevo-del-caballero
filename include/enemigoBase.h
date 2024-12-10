#ifndef ENEMIGOBASE_H_INCLUDED
#define ENEMIGOBASE_H_INCLUDED
#include "inc.h"
#include "pj.h"
class enemigoBase:public sf::Drawable,public colisionable{
    protected:
        ///La base de todos los enemigos
        ///Cada enemigo heredado ingresa su propia texture y Sprite
        sf::Sprite e_sprite;
        sf::Texture _textureE;
        sf::Vector2f e_velocity={};

        //Cada enemigo define el tamaño propio de cada hitbox.
        sf::RectangleShape en_hitbox;
        //Detecta si el personaje interactua con el enemigo de frente.
        sf::RectangleShape attackHitbox;
        //Daña al personaje si interactua con esta hitbox.
        sf::RectangleShape damageHitbox;

        int _direccion=-1;
        int e_vida;
        //Parametros de setSpritePosition
        int startInX;
        int startInY;
        int limitA;
        int limitB;
        int damage;

        //Esto controla las frames de los sprites.
        float _frame=0;
        float _frame2=0;
        float _frame3=0;
        float countdown=0;

        //Controla la duración de los ataques y la ventana donde el personaje recibe daño
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
