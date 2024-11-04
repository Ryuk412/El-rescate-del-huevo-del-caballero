#ifndef NUEVAPARTIDA_H
#define NUEVAPARTIDA_H

#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "ArchivoJugadores.h"

#include <iostream>
using namespace std;

class NuevaPartida{
private:
    sf::Texture _nuevaPartidaTextura;
    sf::Sprite _nuevaPartidaSprite;
    sf::RectangleShape _siguienteHitbox;
    sf::RectangleShape _volverHitBox;
    sf::Font _fuente;
    sf::Text _nombreJugadorTexto;

    Jugador _jugador;
    bool _jugadorCreado=false;

    string _nombreJugador;

    bool _enNuevaPartidaMenu = true;

    bool _volver = false;

public:
    NuevaPartida();
    void procesarEventoEntrada(sf::Event &evento);
    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();
    void dibujar(sf::RenderWindow &ventana);
    void confirmarJugador();
};

#endif // NUEVAPARTIDA_H

