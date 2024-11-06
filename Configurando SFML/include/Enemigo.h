#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <SFML/Graphics.hpp>

class Enemigo
{
    public:
        Enemigo();

    private:
        sf::Texture _enemigoTextura;
        sf::Sprite _enemigo;
};


#endif // ENEMIGO_H
