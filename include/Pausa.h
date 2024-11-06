#ifndef PAUSA_H
#define PAUSA_H

#include <SFML/Graphics.hpp>

class Pausa
{

private:
    sf::Texture _pausaTextura;
    sf::Sprite _pausaSprite;

    sf::RectangleShape _reanudarHitbox;
    sf::RectangleShape _salirHitbox;

    bool _reanudar=false;
    bool _salir=false;

    bool _enPausa=true;
    bool _enReanudar=false;
    bool _enMenu=false;

public:
    Pausa();
    void procesarEventoEntrada(sf::Event &evento);

    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

    void dibujar(sf::RenderWindow &ventana);

};


#endif // PAUSA_H
