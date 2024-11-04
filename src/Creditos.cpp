#include "Creditos.h"

Creditos::Creditos(){
    _creditosTextura.loadFromFile("menu/creditos.png");
    _creditos.setTexture(_creditosTextura);
    _creditos.setPosition(0,0);

    _volverHitBox.setSize(sf::Vector2f(70, 20));
    _volverHitBox.setPosition(365, 529);
    _volverHitBox.setFillColor(sf::Color::Transparent);
    _volverHitBox.setOutlineColor(sf::Color::Red);
    _volverHitBox.setOutlineThickness(2);
}

void Creditos::procesarEventoEntrada(sf::Event &evento){
    if(evento.type == sf::Event::MouseButtonPressed){
        if(_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
            _volver=true;
        }
    }
}

sf::RectangleShape Creditos::getVolverHitbox(){return _volverHitBox;}
void Creditos::setVolver(bool volver){_volver=volver;}
bool Creditos::getVolver(){return _volver;}

void Creditos::dibujar(sf::RenderWindow &ventana){
    ventana.draw(_creditos);
    ventana.draw(_volverHitBox);
}
