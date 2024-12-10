#ifndef JEFE_H
#define JEFE_H
#include "inc.h"
#include "pj.h"
#include "enemigoBase.h"

class Jefe:public enemigoBase {
    public:
        Jefe();
        void attackFrames() override;
        void update(pj ejemplo) override;
};

#endif // JEFE_H
