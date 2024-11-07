#include "Ranking.h"

Ranking::Ranking(){
    _rankingTextura.loadFromFile("menu/ranking.png");
    _rankingSprite.setTexture(_rankingTextura);
    _rankingSprite.setPosition(0, 0);

    _volverHitBox.setSize(sf::Vector2f(70, 18));
    _volverHitBox.setPosition(365, 530);
    _volverHitBox.setFillColor(sf::Color::Transparent);
}

void Ranking::procesarEventoEntrada(sf::Event &evento){
    if(evento.type == sf::Event::MouseButtonPressed){
        if(_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
            _volver=true;
        }
    }
}

sf::RectangleShape Ranking::getVolverHitbox(){return _volverHitBox;}
void Ranking::setVolver(bool volver){_volver=volver;}
bool Ranking::getVolver(){return _volver;}


void Ranking::dibujar(sf::RenderWindow &ventana){
    ventana.draw(_rankingSprite);
    ventana.draw(_volverHitBox);
}
