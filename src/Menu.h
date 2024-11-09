#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Botones.h"
#include "Jugar.h"
#include "Opciones.h"
#include "Creditos.h"

int menu();

class Pausa{
public:
    Pausa();
    void setFondo();
    void draw(sf::RenderWindow& window);
    bool handleEvent(sf::Event& event, sf::RenderWindow& window);

private:
    Boton volveraljuego;
    Boton salir;
    sf::Texture fondopautx;
    sf::Sprite fondopau;
};
#endif // MENU_H
