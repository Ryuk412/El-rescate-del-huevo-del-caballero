#include "Enemigo.h"

Enemigo::Enemigo()
{
    sf::Texture _enemigoTextura;
    sf::Sprite _enemigo;
    _enemigoTextura.loadFromFile("assets/enemigos/slime.png");
    _enemigo.setTexture(_enemigoTextura);
    _enemigo.setPosition(sf::Vector2f(100,100));
    _enemigo.setTextureRect(sf::IntRect(0, 0, 200, 200));
}
