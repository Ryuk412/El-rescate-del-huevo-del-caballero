#ifndef ENEMIGOGENERICO_H_INCLUDED
#define ENEMIGOGENERICO_H_INCLUDED
#include "inc.h"
#include "enemigoSlime.h"
#include "Jefe.h"
#include "pj.h"

class enemigoGenerico: public sf::Drawable{
    private:
        std::vector<enemigoSlime> slime;
        std::vector<Jefe>osomaloso;
    public:
        enemigoGenerico();
        void setEnemies();
        void updateEnemies(pj& ejemplo);
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        bool verificarColisionEspada(pj& p,sf::RectangleShape hitbox);
        bool verificarColisionEnemigo(sf::RectangleShape hitbox);
        int contador=5;
        int getContador();
};


#endif // ENEMIGOGENERICO_H_INCLUDED
