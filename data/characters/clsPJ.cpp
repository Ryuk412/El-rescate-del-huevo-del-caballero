#include<iostream>
#include "pj.h"
void pj::update(){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            _sprite.move(_velocity,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                _sprite.move(-_velocity,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                _sprite.move(0,-_velocity);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                _sprite.move(0,_velocity);
        }
        if(_sprite.getPosition().x < 0){
            _sprite.setPosition(0, _sprite.getPosition().y);
        }
        if(_sprite.getPosition().y < 0){
            _sprite.setPosition(_sprite.getPosition().x,0);
        }
        if(_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800){
            _sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
        }
        if(_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600){
            _sprite.setPosition(_sprite.getPosition().x,600 - _sprite.getGlobalBounds().height);
        }
}

void pj::draw(sf::RenderTarget& target, sf::RenderStates state)const{
        target.draw(_sprite, state);
}


pj::pj()
{
    _velocity=4;
    _textureM.loadFromFile("data/images/ejemplo.png");
    _sprite.setTexture(_textureM);
    //ctor
}

pj::~pj()
{
    //dtor
}
