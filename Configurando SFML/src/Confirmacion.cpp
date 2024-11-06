#include "Confirmacion.h"

#include <iostream>
using namespace std;

Confirmacion::Confirmacion(){
    _confirmacionTextura.loadFromFile("menu/confirmacion.png");
    _confirmacion.setTexture(_confirmacionTextura);
    _confirmacion.setPosition(0, 0);

    _siHitbox.setSize(sf::Vector2f(160, 60));
    _siHitbox.setPosition(215, 315);
    _siHitbox.setFillColor(sf::Color::Transparent);
    _siHitbox.setOutlineColor(sf::Color::Green);
    _siHitbox.setOutlineThickness(2);

    _noHitbox.setSize(sf::Vector2f(160, 60));
    _noHitbox.setPosition(427, 315);
    _noHitbox.setFillColor(sf::Color::Transparent);
    _noHitbox.setOutlineColor(sf::Color::Blue);
    _noHitbox.setOutlineThickness(2);
}

void Confirmacion::procesarEventoEntrada(sf::Event &evento){
    if (evento.type == sf::Event::MouseButtonPressed){
        if (_siHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){

            _volver = false;
        }
        if (_noHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
            _volver = true;
        }
    }
}

sf::RectangleShape Confirmacion::getVolverHitbox(){
    return _noHitbox;
}

bool Confirmacion::getVolver() {
    return _volver;
}

void Confirmacion::dibujar(sf::RenderWindow &ventana){
    ventana.draw(_confirmacion);
    ventana.draw(_siHitbox);
    ventana.draw(_noHitbox);
}
