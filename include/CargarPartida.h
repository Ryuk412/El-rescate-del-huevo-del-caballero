#ifndef CARGARPARTIDA_H
#define CARGARPARTIDA_H

#include <SFML/Graphics.hpp>
#include <ArchivoJugadores.h>

class CargarPartida{
private:
    sf::Texture _cargarPartidaTextura;
    sf::Sprite _cargarPartidaSprite;
    sf::RectangleShape _volverHitBox;

    bool _volver=false;

    ArchivoJugadores _archivo;

    sf::Font _fuente;
    sf::Text _registroTexto;


public:
    CargarPartida();
    void procesarEventoEntrada(sf::Event &evento);

    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

    void dibujar(sf::RenderWindow &ventana);

};

#endif // CARGARPARTIDA_H
