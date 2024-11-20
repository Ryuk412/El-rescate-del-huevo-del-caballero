#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "inc.h"
#include "enemigoBase.h"

class enemigo:public enemigoBase{

    public:
        enemigo();
        void attackFrames() override;
};

#endif // ENEMIGO_H
