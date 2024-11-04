#ifndef CONFIRMACION_H
#define CONFIRMACION_H

#include <SFML/Graphics.hpp>

class Confirmacion{
private:
    sf::Texture _confirmacionTextura;
    sf::Sprite _confirmacion;

    sf::RectangleShape _siHitbox;
    sf::RectangleShape _noHitbox;


    bool _volver = true;

public:
    Confirmacion();
    void procesarEventoEntrada(sf::Event &evento);
    sf::RectangleShape getVolverHitbox();
    bool getVolver();
    void dibujar(sf::RenderWindow &ventana);
};

#endif // CONFIRMACION_H
