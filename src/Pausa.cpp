#include "Pausa.h"

Pausa::Pausa(){
    _pausaTextura.loadFromFile("menu/pausa_menu.png");
    _pausa.setTexture(_pausaTextura);
    _pausa.setPosition(0, 0);

    _reanudarHitbox.setSize(sf::Vector2f(250, 60));
    _reanudarHitbox.setPosition(280, 253);
    _reanudarHitbox.setFillColor(sf::Color::Transparent);
    _reanudarHitbox.setOutlineColor(sf::Color::Blue);
    _reanudarHitbox.setOutlineThickness(2);

    _salirHitbox.setSize(sf::Vector2f(250, 60));
    _salirHitbox.setPosition(280, 340);
    _salirHitbox.setFillColor(sf::Color::Transparent);
    _salirHitbox.setOutlineColor(sf::Color::Green);
    _salirHitbox.setOutlineThickness(2);
}

bool Pausa::procesarEventoEntrada(sf::Event &evento) {

    if (evento.type == sf::Event::MouseButtonPressed) {

        if(_enPausa){
            if(_reanudarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enPausa=false;
                _enReanudar=true;
            }
            else if(_salirHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enPausa=false;
                _enSalir=true;
                return true;
            }
        }
    }
    return false;
}

void Pausa::dibujar(sf::RenderWindow &ventana) {
    if(_enPausa){
        ventana.draw(_pausa);
        ventana.draw(_reanudarHitbox);
        ventana.draw(_salirHitbox);
    }
}
