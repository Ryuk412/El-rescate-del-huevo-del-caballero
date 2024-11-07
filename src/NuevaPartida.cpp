#include "NuevaPartida.h"
#include <iostream>
using namespace std;

NuevaPartida::NuevaPartida(sf::RenderWindow& window) : _window(window), _historia(_window) {
    _nuevaPartidaTextura.loadFromFile("menu/nueva_partida.png");
    _nuevaPartidaSprite.setTexture(_nuevaPartidaTextura);
    _nuevaPartidaSprite.setPosition(0, 0);

    _siguienteHitbox.setSize(sf::Vector2f(60, 60));
    _siguienteHitbox.setPosition(647, 485);
    _siguienteHitbox.setFillColor(sf::Color::Transparent);

    _volverHitBox.setSize(sf::Vector2f(70, 18));
    _volverHitBox.setPosition(365, 465);
    _volverHitBox.setFillColor(sf::Color::Transparent);

    _fuente.loadFromFile("menu/fuente/Arimo-Bold.ttf");
    _nombreJugadorTexto.setFont(_fuente);
    _nombreJugadorTexto.setFillColor(sf::Color::White);
    _nombreJugadorTexto.setCharacterSize(35);
    _nombreJugadorTexto.setPosition(310, 305);
}

void NuevaPartida::procesarEventoEntrada(sf::Event &evento) {

    ///verificar si el evento es un clic del mouse
    if (evento.type == sf::Event::MouseButtonPressed) {

        if (_enNuevaPartida && !_jugadorCreado){

            if (_siguienteHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _jugador.setNombre(_nombreJugador);
                _jugadorCreado = true;
                _archivo.grabarRegistro(_jugador);
                _enNuevaPartida= false;
                _enHistoria = true;
            }

            else if (_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _volver = true;
            }
        }
        else if (_enHistoria) {
            _historia.procesarEventoEntrada(evento);
        }
    }

    ///verifica si el evento es de tipo txt ingresado por teclado
    if (evento.type == sf::Event::TextEntered && _enNuevaPartida){

        if (evento.text.unicode < 128) { ///verifica si es un caracter ASCII estandar

            char character = static_cast<char>(evento.text.unicode);

            if (character == '\b') { ///Boton Retroceso
                _nombreJugador.pop_back();
            } else if (_nombreJugador.length() < 15){ ///max 15 caracteres
                _nombreJugador += character;
            }
            _nombreJugadorTexto.setString(_nombreJugador); ///actualiza el txt por la ventana
        }
    }
}

sf::RectangleShape NuevaPartida::getVolverHitbox() {
    return _volverHitBox;
}

void NuevaPartida::setVolver(bool volver) {
    _volver = volver;
}

bool NuevaPartida::getVolver() {
    return _volver;
}

void NuevaPartida::dibujar(sf::RenderWindow &ventana) {
    ventana.clear();
    ventana.draw(_nuevaPartidaSprite);

    if (_enNuevaPartida) {
        ventana.draw(_siguienteHitbox);
        ventana.draw(_volverHitBox);
        ventana.draw(_nombreJugadorTexto);
    }

    if (_enHistoria) {
        _historia.dibujar(ventana);
    }
}
