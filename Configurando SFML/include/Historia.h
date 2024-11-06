#ifndef HISTORIA_H
#define HISTORIA_H

#include <SFML/Graphics.hpp>

class Historia {
private:
    sf::Texture _espacioTextura;
    sf::Sprite _espacioSprite;

    sf::Texture _historiaTextura;
    sf::Sprite _historiaSprite;

    sf::RectangleShape _empezarHitbox;
    sf::RectangleShape _pausarHitbox;

public:
    Historia();
    void procesarEventoEntrada(sf::Event &evento);
    void dibujar(sf::RenderWindow &ventana);
};

#endif // HISTORIA_H
