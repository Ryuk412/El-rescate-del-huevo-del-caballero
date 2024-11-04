#ifndef OPCIONES_H
#define OPCIONES_H

#include <SFML/Graphics.hpp>

#include "ComoJugar.h"
#include "Ranking.h"

class Opciones
{
private:
    sf::Texture _opcionesTextura;
    sf::Sprite _opciones;

    sf::RectangleShape _rankingHitbox;
    sf::RectangleShape _comoJugarHitbox;
    sf::RectangleShape _eliminarPartidasHitbox;
    sf::RectangleShape _volverHitbox;

    sf::Font _fuente;

    sf::Text _rankingTexto;
    sf::Text _comoJugarTexto;
    sf::Text _eliminarPartidasTexto;

    bool _enRanking=false;
    bool _enComoJugar=false;
    bool _enEliminarPartidas=false;
    bool _enOpcionesMenu=true;
    bool _volver=false;

    Ranking _ranking;
    ComoJugar _comoJugar;

public:
    Opciones();
    void procesarEventoEntrada(sf::Event &evento);

    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

    void dibujar(sf::RenderWindow &ventana);
};

#endif // OPCIONES_H
