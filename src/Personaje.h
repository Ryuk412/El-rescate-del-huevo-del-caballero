#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>

class Personaje
{
    public:
        Personaje();

    private:
        sf::Texture _personajeTextura;
        sf::Sprite _personaje;
};

#endif // PERSONAJE_H
