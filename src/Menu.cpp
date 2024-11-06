#include "Menu.h"

Menu::Menu()
{
    _fondoTextura.loadFromFile("menu/menu_principal.png");
    _fondo.setTexture(_fondoTextura);
    _musica.reproducir(); /// inicia la reproduccion de la musica

    _jugarHitbox.setSize(sf::Vector2f(200, 55));
    _jugarHitbox.setPosition(300, 240);
    _jugarHitbox.setFillColor(sf::Color::Transparent);

    _opcionesHitbox.setSize(sf::Vector2f(200, 55));
    _opcionesHitbox.setPosition(300, 328);
    _opcionesHitbox.setFillColor(sf::Color::Transparent);

    _creditosHitbox.setSize(sf::Vector2f(200, 55));
    _creditosHitbox.setPosition(300, 415);
    _creditosHitbox.setFillColor(sf::Color::Transparent);

    _salirHitbox.setSize(sf::Vector2f(200, 55));
    _salirHitbox.setPosition(300, 500);
    _salirHitbox.setFillColor(sf::Color::Transparent);

    _fuente.loadFromFile("menu/fuente/PixelifySans-Bold.ttf");

    _jugarTexto.setFont(_fuente);
    _jugarTexto.setString("JUGAR");
    _jugarTexto.setCharacterSize(28);
    _jugarTexto.setFillColor(sf::Color::White);
    _jugarTexto.setPosition(357, 252);

    _opcionesTexto.setFont(_fuente);
    _opcionesTexto.setString("OPCIONES");
    _opcionesTexto.setCharacterSize(28);
    _opcionesTexto.setFillColor(sf::Color::White);
    _opcionesTexto.setPosition(337, 337);

    _creditosTexto.setFont(_fuente);
    _creditosTexto.setString("CRÉDITOS");
    _creditosTexto.setCharacterSize(28);
    _creditosTexto.setFillColor(sf::Color::White);
    _creditosTexto.setPosition(338, 423);

    _salirTexto.setFont(_fuente);
    _salirTexto.setString("SALIR");
    _salirTexto.setCharacterSize(28);
    _salirTexto.setFillColor(sf::Color::White);
    _salirTexto.setPosition(360, 508);
}

void Menu::procesarEventoEntrada(sf::Event &evento){

    _musica.procesarEventoEntrada(evento);

    if(_enJugar){
            _jugar.procesarEventoEntrada(evento);
            if (_jugar.getVolver()){
                _enJugar = false;
                _jugar.setVolver(false);
            }
    }
    else if(_enOpciones){
            _opciones.procesarEventoEntrada(evento);
            if (_opciones.getVolver()) {
                _enOpciones = false;
                _opciones.setVolver(false);
            }
    }else if (_enCreditos) {
        _creditos.procesarEventoEntrada(evento);
        if (_creditos.getVolver()) {
            _enCreditos = false;
            _creditos.setVolver(false);
        }
    }

    else{
        if(evento.type == sf::Event::MouseButtonPressed){

            if (_jugarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enJugar = true;
            } else if (_opcionesHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enOpciones = true;
            } else if (_creditosHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enCreditos = true;
            } else if (_salirHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _musica.detener();
                exit(0);
            }
        }
    }

}

void Menu::dibujar(sf::RenderWindow &ventana){

    ventana.clear();
    ventana.draw(_fondo);

     if(!_enJugar && !_enOpciones && !_enCreditos){
        ventana.draw(_jugarHitbox);
        ventana.draw(_opcionesHitbox);
        ventana.draw(_creditosHitbox);
        ventana.draw(_salirHitbox);
    }

    ventana.draw(_jugarTexto);
    ventana.draw(_opcionesTexto);
    ventana.draw(_creditosTexto);
    ventana.draw(_salirTexto);

    if(_enJugar){_jugar.dibujar(ventana);}
    else if(_enOpciones){_opciones.dibujar(ventana);}
    else if(_enCreditos){_creditos.dibujar(ventana);}
}
