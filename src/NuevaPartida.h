#ifndef NUEVAPARTIDA_H
#define NUEVAPARTIDA_H
#include "Jugador.h"
#include <SFML/Graphics.hpp>
#include "Confirmacion.h"

class NuevaPartida {
private:
    sf::Texture _nuevaPartidaTextura;
    sf::Sprite _nuevaPartidaSprite;
    sf::RectangleShape _siguienteHitbox;
    sf::RectangleShape _volverHitBox;
    sf::Font _fuente;
    sf::Text _nombreJugadorTexto;
    Jugador jugador1;

    char _nombreJugador[16]={0}; /// 15 caracteres + '\0'
    int _longitudNombre=0;

    bool _enNuevaPartidaMenu = true;
    bool _enConfirmacion = false;

    Confirmacion _confirmacion;

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

