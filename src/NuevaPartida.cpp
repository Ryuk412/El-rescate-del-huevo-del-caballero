#include "NuevaPartida.h"
#include <iostream>
using namespace std;

NuevaPartida::NuevaPartida(){

    _nuevaPartidaTextura.loadFromFile("menu/nueva_partida.png");
    _nuevaPartidaSprite.setTexture(_nuevaPartidaTextura);
    _nuevaPartidaSprite.setPosition(0, 0);

    ///hitboxes - propiedades
    _siguienteHitbox.setSize(sf::Vector2f(60, 60));
    _siguienteHitbox.setPosition(647, 485);
    _siguienteHitbox.setFillColor(sf::Color::Transparent);

    _volverHitBox.setSize(sf::Vector2f(70, 18));
    _volverHitBox.setPosition(365, 465);
    _volverHitBox.setFillColor(sf::Color::Transparent);

    ///texto - propiedades
    _fuente.loadFromFile("menu/fuente/Arimo-Bold.ttf");
    _nombreJugadorTexto.setFont(_fuente);
    _nombreJugadorTexto.setFillColor(sf::Color::White);
    _nombreJugadorTexto.setCharacterSize(35);
    _nombreJugadorTexto.setPosition(310, 305);
}

void NuevaPartida::procesarEventoEntrada(sf::Event &evento){

    ///verifica si el evento es un clic del mouse
    if (evento.type == sf::Event::MouseButtonPressed){

        if (_enNuevaPartida && !_jugadorCreado){

            ///verifica si el clic está dentro de la hitbox de "Siguiente"
            if (_siguienteHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _jugador.setNombre(_nombreJugador);
                _jugadorCreado = true;
                _archivo.grabarRegistro(_jugador);
                _enNuevaPartida= false;
                _enHistoria = true;
            }
            ///verifica si el clic esta dentro de la hitbox de "Volver"
            else if(_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){_volver = true;}
        }

        else if(_enHistoria){_historia.procesarEventoEntrada(evento);}
    }

    ///verifica si el evento es de tipo texto ingresado por el teclado
    if (evento.type == sf::Event::TextEntered && _enNuevaPartida){

        if (evento.text.unicode < 128){ ///valor unicode sist de codif estandar(para representar txt en comp de manera universal)

            char character = static_cast<char>(evento.text.unicode);///convierte al val unicode a char

            if(character == '\b'){ ///Boton Retroceso
                _nombreJugador.pop_back();///elimina el ult caracter
            }
            else if(_nombreJugador.length() < 15){
                _nombreJugador += character;
            }
            _nombreJugadorTexto.setString(_nombreJugador);///actualiza el txt en pantalla
        }
    }
}

sf::RectangleShape NuevaPartida::getVolverHitbox(){return _volverHitBox;}
void NuevaPartida::setVolver(bool volver){_volver = volver;}
bool NuevaPartida::getVolver(){return _volver;}

void NuevaPartida::dibujar(sf::RenderWindow &ventana){

    ventana.clear();
    ventana.draw(_nuevaPartidaSprite);

    if (_enNuevaPartida){
        ventana.draw(_siguienteHitbox);
        ventana.draw(_volverHitBox);
        ventana.draw(_nombreJugadorTexto);
    }

    if (_enHistoria){
        _historia.dibujar(ventana);
    }
}
