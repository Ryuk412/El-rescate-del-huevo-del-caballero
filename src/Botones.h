#ifndef BOTONES_H
#define BOTONES_H

#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Boton{
public:
    sf::RectangleShape formaboton;
    sf::Text botontexto;
    sf::Font fuente;

    Boton(float x, float y, float ancho, float alto, const std::string& texto);
    void draw(sf::RenderWindow& window);
    bool MouseClick(sf::RenderWindow& window);
};


#endif // BOTONES_H
