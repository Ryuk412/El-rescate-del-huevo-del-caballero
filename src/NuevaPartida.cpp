#include "NuevaPartida.h"
#include <iostream>
#include <cstring>

NuevaPartida::NuevaPartida() {
    _nuevaPartidaTextura.loadFromFile("menu/nueva_partida.png");
    _nuevaPartidaSprite.setTexture(_nuevaPartidaTextura);
    _nuevaPartidaSprite.setPosition(0, 0);


    /// Hitboxes: Si y No - Propiedades
    _siguienteHitbox.setSize(sf::Vector2f(60, 60));
    _siguienteHitbox.setPosition(647, 485);
    _siguienteHitbox.setFillColor(sf::Color::Transparent);
    _siguienteHitbox.setOutlineColor(sf::Color::Green);
    _siguienteHitbox.setOutlineThickness(2);

    _volverHitBox.setSize(sf::Vector2f(70, 18));
    _volverHitBox.setPosition(365, 465);
    _volverHitBox.setFillColor(sf::Color::Transparent);
    _volverHitBox.setOutlineColor(sf::Color::Red);
    _volverHitBox.setOutlineThickness(2);

    /// Texto ingresado por teclado - Propiedades
    _fuente.loadFromFile("menu/fuente/Arimo-Bold.ttf");
    _nombreJugadorTexto.setFont(_fuente);
    _nombreJugadorTexto.setFillColor(sf::Color::White);
    _nombreJugadorTexto.setCharacterSize(35);
    _nombreJugadorTexto.setPosition(310, 305);
}

void NuevaPartida::procesarEventoEntrada(sf::Event &evento){
    if(evento.type == sf::Event::MouseButtonPressed){
        if(_enNuevaPartidaMenu){
            if (_siguienteHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _enConfirmacion=true;
                _enNuevaPartidaMenu=false;
            } else if(_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _volver=true;
            }
        } else if(_enConfirmacion){
            _confirmacion.procesarEventoEntrada(evento);

            if (_confirmacion.getVolver()){
                _enConfirmacion=false;
                _enNuevaPartidaMenu=true;
            }
        }
    }

    ///si el evento es de tipo texto
    if (evento.type == sf::Event::TextEntered && _enNuevaPartidaMenu) {
        if (evento.text.unicode < 128) { ///acepta solo caracteres ASCII
            char character = static_cast<char>(evento.text.unicode);

            if (character == '\b' && _longitudNombre > 0) { ///boton retroceso y longitud mayor a 0
                _longitudNombre--;
                _nombreJugador[_longitudNombre] = '\0'; ///elimina el último carácter
            } else if (_longitudNombre < 15) { /// la long no tiene q pasar los 15 caracteres
                _nombreJugador[_longitudNombre] = character;
                _longitudNombre++;
                _nombreJugador[_longitudNombre] = '\0';///añade '\0'
            }
            _nombreJugadorTexto.setString(_nombreJugador); ///actualiza el texto en pantalla
            jugador1.setNombreJugador(_nombreJugador);
            system("cls");
            std::cout<<jugador1.getNombreJugador();
        }
    }
}

sf::RectangleShape NuevaPartida::getVolverHitbox(){return _volverHitBox;}
void NuevaPartida::setVolver(bool volver){_volver = volver;}
bool NuevaPartida::getVolver(){return _volver;}

void NuevaPartida::dibujar(sf::RenderWindow &ventana){
    ventana.clear();
    ventana.draw(_nuevaPartidaSprite);

    if (_enNuevaPartidaMenu) {
        ventana.draw(_siguienteHitbox);
        ventana.draw(_volverHitBox);
        ventana.draw(_nombreJugadorTexto);
    }
    if (_enConfirmacion) {
        _confirmacion.dibujar(ventana);
    }
}
