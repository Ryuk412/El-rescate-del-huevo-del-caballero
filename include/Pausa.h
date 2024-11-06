#ifndef PAUSA_H
#define PAUSA_H

#include <SFML/Graphics.hpp>

class Pausa {
private:
    sf::Texture _pausaTextura;
    sf::Sprite _pausa;

    sf::RectangleShape _reanudarHitbox;
    sf::RectangleShape _salirHitbox;

    bool _enPausa = true;
    bool _enReanudar = false;
    bool _enSalir = false;

public:
    Pausa();

    bool procesarEventoEntrada(sf::Event &evento);
    void dibujar(sf::RenderWindow &ventana);

    bool deseaSalir() const { return _enSalir; }
};

#endif // PAUSA_H
