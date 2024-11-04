#ifndef CREDITOS_H
#define CREDITOS_H

#include <SFML/Graphics.hpp>

class Creditos
{
private:
    sf::Texture _creditosTextura;
    sf::Sprite _creditos;

    sf::RectangleShape _volverHitBox;

    bool _volver=false;

public:
    Creditos();
    void procesarEventoEntrada(sf::Event &evento);

    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

    void dibujar(sf::RenderWindow &ventana);

};

#endif // CREDITOS_H
