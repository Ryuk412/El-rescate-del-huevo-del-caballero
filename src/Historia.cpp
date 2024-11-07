#include "Historia.h"
#include <iostream>
using namespace std;

Historia::Historia() {
    _historiaTextura.loadFromFile("menu/historia.png");
    _historiaSprite.setTexture(_historiaTextura);
    _historiaSprite.setPosition(0, 0);

    _empezarHitbox.setSize(sf::Vector2f(276, 37));
    _empezarHitbox.setPosition(256, 500);
    _empezarHitbox.setFillColor(sf::Color::Transparent);
    _empezarHitbox.setOutlineColor(sf::Color::Green);
    _empezarHitbox.setOutlineThickness(2);

    _pausarHitbox.setSize(sf::Vector2f(50, 46));
    _pausarHitbox.setPosition(690, 60);
    _pausarHitbox.setFillColor(sf::Color::Transparent);
    _pausarHitbox.setOutlineColor(sf::Color::Green);
    _pausarHitbox.setOutlineThickness(2);
}

void Historia::procesarEventoEntrada(sf::Event &evento) {
    if (evento.type == sf::Event::MouseButtonPressed) {

        if (_enHistoria){
            if (_empezarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                game game;
                while (game.isRunning()) {
                    game.update();
                    game.render();
                }

                _enPausa = false;
                _enEmpezar = true;
            }

            if (_pausarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enHistoria = false;
                _enPausa = true;
            }
        }

        if (_enPausa) {
            _pausa.procesarEventoEntrada(evento);
        }
    }
}

void Historia::dibujar(sf::RenderWindow &ventana) {
    if (_enHistoria) { // Solo dibujamos la historia cuando estamos en ese menú
        ventana.draw(_historiaSprite);
        ventana.draw(_empezarHitbox);
        ventana.draw(_pausarHitbox);
    }
    else if (_enPausa) { // Solo dibujamos la pausa cuando estamos en ese menú
        _pausa.dibujar(ventana);
    }
}

