#ifndef ENEMIGOSLIME_H
#define ENEMIGOSLIME_H
#include "inc.h"

class enemigoSlime : public colisionable , public sf::Drawable
{
    public:
        enemigoSlime();
        void update(int limitA, int limitB);
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        sf::RectangleShape getHitbox()const override;
        void respawn();
        bool muerte();
        bool isAlive();
        void danioRecibido(int danio);
        void setSpritePosition(int posicionX, int posicionY);
        virtual ~enemigoSlime();

    protected:

    private:
    sf::RectangleShape slm_hitbox;
    int _direccion=-1;
    sf::Sprite slm_sprite;
    sf::Texture _textureSlm;
    sf::Vector2f slm_velocity={0,0};
    float _frame=0;
    float _frame2=0;
    float _frame3=0;
    int slm_vida;
};

#endif // ENEMIGOSLIME_H
