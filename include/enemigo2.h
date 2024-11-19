#ifndef ENEMIGO2_H_INCLUDED
#define ENEMIGO2_H_INCLUDED
#include "inc.h"
#include "enemigoBase.h"

class enemigo2:  public sf::Drawable, public colisionable, public enemigoBase{
    public:
        enemigo2();
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        sf::RectangleShape getHitbox()const override;
        void attackFrames() override;
};

#endif // ENEMIGO2_H_INCLUDED
