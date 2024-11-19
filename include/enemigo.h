#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "inc.h"
#include "enemigoBase.h"

class enemigo: public colisionable, public enemigoBase{

    public:
        enemigo();
        sf::RectangleShape getHitbox()const override;
        void attackFrames() override;
};

#endif // ENEMIGO_H
