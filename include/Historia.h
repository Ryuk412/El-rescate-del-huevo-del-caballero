#ifndef HISTORIA_H
#define HISTORIA_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include "game.h"
#include "Pausa.h"

using namespace std;
using namespace sf;

class Historia {
private:
    sf::Texture _espacioTextura;
    sf::Sprite _espacioSprite;

    sf::Texture _historiaTextura;
    sf::Sprite _historiaSprite;

    sf::RectangleShape _empezarHitbox;
    sf::RectangleShape _pausarHitbox;

    Pausa _pausa;

    bool _enMenu = false;
    bool _enHistoria = true;
    bool _enEmpezar = false;
    bool _enPausa = false;

public:
    Historia();
    void procesarEventoEntrada(sf::Event &evento);
    void dibujar(sf::RenderWindow &ventana);
};

#endif // HISTORIA_H
