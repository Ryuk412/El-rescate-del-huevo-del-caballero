#include "NuevaPartida.h"
#include <cstring>

#include <iostream>
using namespace std;

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
    if (evento.type == sf::Event::MouseButtonPressed){

        if (_enNuevaPartidaMenu){

            if (_siguienteHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){

                cout<<"se dio clic en SI"<<endl;
                _jugador.setNombre(_nombreJugador);
                _jugadorCreado=true;

                if(_jugadorCreado==true){
                        cout<<"Jugador Creado esta en True"<<endl<<endl;
                        cout<<"Nombre del jugador: "<<_jugador.getNombre()<<endl;

                    ArchivoJugadores archivoJugadores;
                    if(archivoJugadores.grabarRegistro(_jugador)){
                        cout<<"Si se creo el registo"<<endl<<" - Nombre: "<<_jugador.getNombre();
                    }else{
                        cout<<"No se creo el registro"<<endl;

                    }
                }
                else if(_jugadorCreado==false){
                    cout<<"Sigue Jugador Creado en False"<<endl;
                }

                _enNuevaPartidaMenu=false;

            }
            else if(_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _volver=true;
            }
        }
    }

    ///si el evento es de tipo texto
    if (evento.type == sf::Event::TextEntered && _enNuevaPartidaMenu) {

        if (evento.text.unicode < 128) { ///acepta solo caracteres ASCII
            char character = static_cast<char>(evento.text.unicode);

            if (character == '\b' && !_nombreJugador.empty()) { ///botn retroceso
                _nombreJugador.pop_back(); ///elimina el ultimo caracter
            } else if (_nombreJugador.length() < 15) { ///long max a 15 caracteres
                _nombreJugador += character; ///añade el caracter
            }
            _nombreJugadorTexto.setString(_nombreJugador); ///actualiza el texto en pantalla
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
}
