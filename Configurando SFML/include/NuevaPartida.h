#ifndef NUEVAPARTIDA_H
#define NUEVAPARTIDA_H

#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "ArchivoJugadores.h"
#include "Historia.h"

class NuevaPartida {
private:
    sf::Texture _nuevaPartidaTextura;
    sf::Sprite _nuevaPartidaSprite;
    sf::RectangleShape _siguienteHitbox;
    sf::RectangleShape _volverHitBox;

    sf::Font _fuente;
    sf::Text _nombreJugadorTexto;

    ArchivoJugadores _archivo;
    Jugador _jugador;
    Historia _historia;

    std::string _nombreJugador;

    ///banderas
    bool _enNuevaPartidaMenu = true;
    bool _jugadorCreado=false;
    bool _enHistoria = false;
    bool _volver = false;

public:
    NuevaPartida();
    void procesarEventoEntrada(sf::Event &evento);
    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();
    void dibujar(sf::RenderWindow &ventana);
};

#endif // NUEVAPARTIDA_H

