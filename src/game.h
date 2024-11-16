#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "enemigo.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "Jefe.h"
#include "clsPJ.h"
#include "Item.h"
#include "mapa.h"
#include "enemigoEsqueleto.h"
#include "enemigoSlime.h"
#include "itemPuntos.h"
#include "Botones.h"
#include "Pausa.h"

class game{

private:

    sf::Event evento;
    sf::View camara;

    pj ejemplo;
    Item corazon;
    int contador;
    itemPuntos star;
    sf::Font font;
    sf::Text textoTest;
    float limiteCamaraIzq=400;
    float limiteCamaraDer=1200;

    Boton pausa;
    bool enPausa;

public:
    game(sf::RenderWindow& window);
    virtual ~game();
    const bool isRunning(sf::RenderWindow& window) const;
    void updateEvent(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

};

#endif // GAME_H_INCLUDED
