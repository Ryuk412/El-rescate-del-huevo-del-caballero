#ifndef MUSICA_H
#define MUSICA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Musica{
private:
    sf::Music _musica;
    sf::RectangleShape _musicaHitbox;

public:
    Musica();
    void reproducir();
    void pausar();
    void detener();
    void procesarEventoEntrada(sf::Event &evento);
    void dibujar(sf::RenderWindow &ventana);
};

#endif // MUSICA_H
