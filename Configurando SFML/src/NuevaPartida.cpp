#include "NuevaPartida.h"
#include <iostream>
using namespace std;

NuevaPartida::NuevaPartida() {
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

void NuevaPartida::procesarEventoEntrada(sf::Event &evento){

    ///si el evento es de tipo click del mouse
    if(evento.type == sf::Event::MouseButtonPressed){

        if(_enNuevaPartidaMenu){

            ///verifica si el click del mouse esta dentro de los limites de la hitbox Siguiente
            if(_siguienteHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){

                _jugador.setNombre(_nombreJugador);
                _jugadorCreado = true;
                _archivo.grabarRegistro(_jugador);
                _enNuevaPartidaMenu = false;
                _enHistoria = true;
            }
            ///verifica si el click del mouse esta dentro de los limites de la hitbox Volver
            else if (_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _volver = true;
            }
        }

        else if(_enHistoria){
            _historia.procesarEventoEntrada(evento);
        }
    }

    ///si el evento es de tipo ingreso de texto y si esta en el menu NuevaPartida
    if(evento.type == sf::Event::TextEntered && _enNuevaPartidaMenu){

        if (evento.text.unicode < 128){ ///verifica si el caracter ingresado es un caracter ASCII (valores menores a 128)

            char character= static_cast<char>(evento.text.unicode);  ///convierte el valor unicode a un caracter tipo char

                if (character == '\b'){ ///si el caracter es el de retroceso (borrar)
                    _nombreJugador.pop_back();///elimina el último caracter del nombre del jugador
                }
                else if (_nombreJugador.length() < 10){///si el nombre del jugador tiene menos de 10 caracteres
                    _nombreJugador += character;///agrega el nuevo caracter al nombre del jugador
                }
                _nombreJugadorTexto.setString(_nombreJugador);  ///actualiza el texto que muestra el nombre del jugador en pantalla
        }

    }

}

sf::RectangleShape NuevaPartida::getVolverHitbox(){
    return _volverHitBox;
}

void NuevaPartida::setVolver(bool volver){
    _volver = volver;
}

bool NuevaPartida::getVolver(){
    return _volver;
}

void NuevaPartida::dibujar(sf::RenderWindow &ventana){

    ventana.clear();
    ventana.draw(_nuevaPartidaSprite);

    if(_enNuevaPartidaMenu){
        ventana.draw(_siguienteHitbox);
        ventana.draw(_volverHitBox);
        ventana.draw(_nombreJugadorTexto);
    }

    if(_enHistoria){
        _historia.dibujar(ventana);
    }
}
