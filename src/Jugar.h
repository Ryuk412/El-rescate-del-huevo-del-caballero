#ifndef JUGAR_H
#define JUGAR_H

#include <SFML/Graphics.hpp>
#include "CargarPartida.h"
#include "NuevaPartida.h"

class Jugar
{
private:
    sf::Texture _jugarTextura;
    sf::Sprite _jugar;

    sf::RectangleShape _cargarPartidaHitbox;
    sf::RectangleShape _nuevaPartidaHitbox;
    sf::RectangleShape _volverHitBox;

    sf::Font _fuente;

    sf::Text _cargarPartidaTexto;
    sf::Text _nuevaPartidaTexto;

    CargarPartida _cargarPartida;
    NuevaPartida _nuevaPartida;

    bool _enCargarPartida=false;
    bool _enNuevaPartida=false;
    bool _enJugarMenu=true;
    bool _volver=false;

public:
    Jugar();
    void procesarEventoEntrada(sf::Event &evento);

    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

    void dibujar(sf::RenderWindow &ventana);
};

#endif // JUGAR_H
