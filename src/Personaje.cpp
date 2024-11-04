#include "Personaje.h"

Personaje::Personaje()
{
    sf::Texture _personajeTextura;
    sf::Sprite _personaje;
    _personajeTextura.loadFromFile("assets/caballero/caballero.png");
    _personaje.setTexture(_personajeTextura);
    _personaje.setPosition(sf::Vector2f(0,0));
    _personaje.setTextureRect(sf::IntRect(0, 0, 200, 200));
}
