#ifndef ENEMIGO2_H_INCLUDED
#define ENEMIGO2_H_INCLUDED
#include "inc.h"
#include "enemigoBase.h"

class enemigo2:public enemigoBase{
    public:
        enemigo2();
        void attackFrames() override;
};

#endif // ENEMIGO2_H_INCLUDED
