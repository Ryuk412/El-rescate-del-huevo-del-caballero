#include <iostream>
#include "Opciones.h"

using namespace std;

Opciones::Opciones(){
    _opcionesTextura.loadFromFile("menu/opciones.png");
    _opciones.setTexture(_opcionesTextura);
    _opciones.setPosition(0,0);

    _rankingHitbox.setSize(sf::Vector2f(320, 55));
    _rankingHitbox.setPosition(243, 230);
    _rankingHitbox.setFillColor(sf::Color::Transparent);
    _rankingHitbox.setOutlineColor(sf::Color::Blue);
    _rankingHitbox.setOutlineThickness(2);

    _comoJugarHitbox.setSize(sf::Vector2f(320, 56));
    _comoJugarHitbox.setPosition(243, 314);
    _comoJugarHitbox.setFillColor(sf::Color::Transparent);
    _comoJugarHitbox.setOutlineColor(sf::Color::Green);
    _comoJugarHitbox.setOutlineThickness(2);

    _eliminarPartidasHitbox.setSize(sf::Vector2f(320, 55));
    _eliminarPartidasHitbox.setPosition(243, 402);
    _eliminarPartidasHitbox.setFillColor(sf::Color::Transparent);
    _eliminarPartidasHitbox.setOutlineColor(sf::Color::Magenta);
    _eliminarPartidasHitbox.setOutlineThickness(2);

    _volverHitbox.setSize(sf::Vector2f(70, 20));
    _volverHitbox.setPosition(365, 485);
    _volverHitbox.setFillColor(sf::Color::Transparent);
    _volverHitbox.setOutlineColor(sf::Color::Yellow);
    _volverHitbox.setOutlineThickness(2);


    _fuente.loadFromFile("menu/fuente/PixelifySans-Bold.ttf");

    _rankingTexto.setFont(_fuente);
    _rankingTexto.setString("RANKING");
    _rankingTexto.setCharacterSize(28);
    _rankingTexto.setFillColor(sf::Color::White);
    _rankingTexto.setPosition(340, 237);

    _comoJugarTexto.setFont(_fuente);
    _comoJugarTexto.setString("COMO JUGAR");
    _comoJugarTexto.setCharacterSize(28);
    _comoJugarTexto.setFillColor(sf::Color::White);
    _comoJugarTexto.setPosition(320, 322);

    _eliminarPartidasTexto.setFont(_fuente);
    _eliminarPartidasTexto.setString("ELIMINAR PARTIDAS");
    _eliminarPartidasTexto.setCharacterSize(28);
    _eliminarPartidasTexto.setFillColor(sf::Color::White);
    _eliminarPartidasTexto.setPosition(274, 411);

}

void Opciones::procesarEventoEntrada(sf::Event &evento){

    /// maneja los eventos del mouse sobre las hitboxes
    if(evento.type == sf::Event::MouseButtonPressed){

        if(_enOpcionesMenu){
            if(_rankingHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _enRanking = true;
                _enOpcionesMenu = false;
            }
            else if(_comoJugarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _enComoJugar = true;
                _enOpcionesMenu = false;
            }
            else if(_eliminarPartidasHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
               ///vaciar archivo (completo)
            }
            else if(_volverHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _volver = true;
            }
        }

        /// recibe el evento de los Volver de cada submenu cuando quieren volver el menu Opciones
        if(_enComoJugar){
                _comoJugar.procesarEventoEntrada(evento);
                if (_comoJugar.getVolverHitbox().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                    _enComoJugar = false;
                    _enOpcionesMenu = true;
                }
        }
        else if(_enRanking){
                _ranking.procesarEventoEntrada(evento);
                if (_ranking.getVolverHitbox().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                    _enRanking = false;
                    _enOpcionesMenu = true;
                }
        }
    }
}

sf::RectangleShape Opciones::getVolverHitbox(){return _volverHitbox;}
void Opciones::setVolver(bool volver){_volver=volver;}
bool Opciones::getVolver(){return _volver;}

void Opciones::dibujar(sf::RenderWindow &ventana){

    ventana.clear();
    ventana.draw(_opciones);

    if (_enOpcionesMenu){
        ventana.draw(_rankingHitbox);
        ventana.draw(_comoJugarHitbox);
        ventana.draw(_eliminarPartidasHitbox);
        ventana.draw(_volverHitbox);
        ventana.draw(_rankingTexto);
        ventana.draw(_comoJugarTexto);
        ventana.draw(_eliminarPartidasTexto);
    }

    if(_enComoJugar){
        _comoJugar.dibujar(ventana);
    }
    if(_enRanking){
        _ranking.dibujar(ventana);
    }

}

