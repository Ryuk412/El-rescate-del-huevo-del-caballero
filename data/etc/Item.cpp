#include<iostream>
#include <stdlib.h>
#include "Item.h"

sf::RectangleShape Item::getHitbox()const{
    return m_hitbox;
}

void Item::respawn(mapa& _objetoMapa){
    _sprite.setPosition(std::rand()%1400+_sprite.getGlobalBounds().width,std::rand() % 400+_sprite.getGlobalBounds().height);
    m_hitbox.setPosition(_sprite.getGlobalBounds().left, _sprite.getGlobalBounds().top);
    if(_objetoMapa.verificarColision(m_hitbox)==true){
    while(_objetoMapa.verificarColision(m_hitbox)==true){
    _sprite.setPosition(std::rand()%1500+_sprite.getGlobalBounds().width,std::rand() % 400+_sprite.getGlobalBounds().height);
    m_hitbox.setPosition(_sprite.getGlobalBounds().left, _sprite.getGlobalBounds().top);
    }

    }
}
void Item::draw(sf::RenderTarget& target, sf::RenderStates state)const{
       target.draw(m_hitbox,state);
        target.draw(_sprite, state);
}

bool Item::getActive(){
    return activo;
}

void Item::setActive(bool e){
    activo=e;
}

Item::Item(){
    _textureM.loadFromFile("data/images/ejemploPU.png");
    _sprite.setTexture(_textureM);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);
    m_hitbox.setSize({_sprite.getGlobalBounds().getSize()});
     m_hitbox.setFillColor(sf::Color::Green);

    //ctor
}


