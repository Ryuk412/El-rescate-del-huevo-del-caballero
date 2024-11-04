#include "Jugar.h"

Jugar::Jugar(){
    _jugarTextura.loadFromFile("menu/jugar.png");
    _jugar.setTexture(_jugarTextura);
    _jugar.setPosition(0,0);

    _cargarPartidaHitbox.setSize(sf::Vector2f(320, 55));
    _cargarPartidaHitbox.setPosition(243, 230);
    _cargarPartidaHitbox.setFillColor(sf::Color::Transparent);
    _cargarPartidaHitbox.setOutlineColor(sf::Color::Blue);
    _cargarPartidaHitbox.setOutlineThickness(2);

    _nuevaPartidaHitbox.setSize(sf::Vector2f(320, 56));
    _nuevaPartidaHitbox.setPosition(243, 314);
    _nuevaPartidaHitbox.setFillColor(sf::Color::Transparent);
    _nuevaPartidaHitbox.setOutlineColor(sf::Color::Green);
    _nuevaPartidaHitbox.setOutlineThickness(2);

    _volverHitBox.setSize(sf::Vector2f(70, 18));
    _volverHitBox.setPosition(365, 465);
    _volverHitBox.setFillColor(sf::Color::Transparent);

    _fuente.loadFromFile("menu/fuente/PixelifySans-Bold.ttf");

    _cargarPartidaTexto.setFont(_fuente);
    _cargarPartidaTexto.setString("CARGAR PARTIDA");
    _cargarPartidaTexto.setCharacterSize(28);
    _cargarPartidaTexto.setFillColor(sf::Color::White);
    _cargarPartidaTexto.setPosition(295, 236);

    _nuevaPartidaTexto.setFont(_fuente);
    _nuevaPartidaTexto.setString("NUEVA PARTIDA");
    _nuevaPartidaTexto.setCharacterSize(28);
    _nuevaPartidaTexto.setFillColor(sf::Color::White);
    _nuevaPartidaTexto.setPosition(300, 325);
}

void Jugar::procesarEventoEntrada(sf::Event &evento){
    if(evento.type == sf::Event::MouseButtonPressed){

        if(_enJugarMenu){

            if(_cargarPartidaHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {

                _enCargarPartida=true;
                _enJugarMenu=false;

            }
            else if(_nuevaPartidaHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enNuevaPartida=true;
                _enJugarMenu=false;
            }
            else if(_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _volver=true;
            }
        }
        else if(_enCargarPartida){
            _cargarPartida.procesarEventoEntrada(evento);
            if (_cargarPartida.getVolverHitbox().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {

                _enCargarPartida=false;
                _enJugarMenu=true;
            }
        }else if(_enNuevaPartida){
            _nuevaPartida.procesarEventoEntrada(evento);
            if(_nuevaPartida.getVolverHitbox().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enNuevaPartida=false;
                _enJugarMenu=true;
            }
        }
    }
    else if(evento.type == sf::Event::TextEntered){
        if(_enNuevaPartida){
            _nuevaPartida.procesarEventoEntrada(evento);
        }
    }
}



sf::RectangleShape Jugar::getVolverHitbox(){return _volverHitBox;}
void Jugar::setVolver(bool volver){_volver=volver;}
bool Jugar::getVolver(){return _volver;}

void Jugar::dibujar(sf::RenderWindow &ventana){

    ventana.clear();
    ventana.draw(_jugar);

    if (_enJugarMenu){
        ventana.draw(_cargarPartidaHitbox);
        ventana.draw(_nuevaPartidaHitbox);
        ventana.draw(_cargarPartidaTexto);
        ventana.draw(_nuevaPartidaTexto);
        ventana.draw(_volverHitBox);
    }

    if(_enCargarPartida){_cargarPartida.dibujar(ventana);}
    if(_enNuevaPartida){_nuevaPartida.dibujar(ventana);}
}
