#include "Pausa.h"

Pausa::Pausa(){

    _pausaTextura.loadFromFile("menu/pausa_menu.png");
    _pausaSprite.setTexture(_pausaTextura);
    _pausaSprite.setPosition(0,0);

    _reanudarHitbox.setSize(sf::Vector2f(70, 20));
    _reanudarHitbox.setPosition(365, 529);
    _reanudarHitbox.setFillColor(sf::Color::Transparent);
    _reanudarHitbox.setOutlineColor(sf::Color::Magenta);
    _reanudarHitbox.setOutlineThickness(2);

    _salirHitbox.setSize(sf::Vector2f(70, 20));
    _salirHitbox.setPosition(365, 529);
    _salirHitbox.setFillColor(sf::Color::Transparent);
    _salirHitbox.setOutlineColor(sf::Color::Magenta);
    _salirHitbox.setOutlineThickness(2);

}
void Pausa::procesarEventoEntrada(sf::Event &evento){

    if(evento.type == sf::Event::MouseButtonPressed){

        if(_enPausa){

            if(_reanudarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){

                _enReanudar=true;
                _enPausa=false;

            }
            else if(_salirHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
                _enMenu=true;
                _enPausa=false;
            }
        }

        else if(_enReanudar){

        }

        }
        else if(_enMenu){

        }
}

sf::RectangleShape Pausa::getVolverHitbox(){
}
void Pausa::setVolver(bool volver){
}

bool Pausa::getVolver(){
}

void Pausa::dibujar(sf::RenderWindow &ventana){

    if(_enPausa){
        ventana.draw(_pausaSprite);
        ventana.draw(_reanudarHitbox);
        ventana.draw(_salirHitbox);
    }
}
