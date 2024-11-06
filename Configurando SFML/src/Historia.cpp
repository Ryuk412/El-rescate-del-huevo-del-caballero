#include "Historia.h"
#include <iostream>
using namespace std;

Historia::Historia(){

    _historiaTextura.loadFromFile("menu/historia.png");
    _historiaSprite.setTexture(_historiaTextura);
    _historiaSprite.setPosition(0, 0);

    _empezarHitbox.setSize(sf::Vector2f(300, 50));
    _empezarHitbox.setPosition(230, 500);
    _empezarHitbox.setFillColor(sf::Color::Transparent);
    _empezarHitbox.setOutlineColor(sf::Color::Green);
    _empezarHitbox.setOutlineThickness(2);

    _pausarHitbox.setSize(sf::Vector2f(50, 50));
    _pausarHitbox.setPosition(680, 65);
    _pausarHitbox.setFillColor(sf::Color::Transparent);
    _pausarHitbox.setOutlineColor(sf::Color::Green);
    _pausarHitbox.setOutlineThickness(2);
}

void Historia::procesarEventoEntrada(sf::Event &evento){

    if(evento.type == sf::Event::MouseButtonPressed){

        if(_empezarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
            cout<<"Clic en Empezar"<<endl;
        }
        else if(_pausarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
            cout<<"Clic en Pausar"<<endl;
        }
    }
}

void Historia::dibujar(sf::RenderWindow &ventana){

    ventana.draw(_historiaSprite);
    ventana.draw(_empezarHitbox);
    ventana.draw(_pausarHitbox);
}
