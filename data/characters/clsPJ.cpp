#include <iostream>
#include "pj.h"
#include "mapa.h"

pj::pj(){
    _textureM.loadFromFile("assets/characters(100x100)/Knight/Knight/Knight.png");
    _sprite.setTexture(_textureM);
    _sprite.setTextureRect({0, 0, 195, 195});
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);

    m_hitbox.setSize({50, 60});
    m_hitbox.setFillColor(sf::Color::Red);
    e_hitbox.setSize({25, 65});
    e_hitbox.setFillColor(sf::Color::Blue);

    _sprite.setPosition(200, 200);

    _vida = 100;
    _bVida.setSize({_vida, 10});
    _bVida.setFillColor(sf::Color::Green);
}

pj::~pj(){}

void pj::update(mapa& _objetoMapa){
    _velocity = {0, _velocity.y};

    ///pj quieto
    if(_velocity.x == 0 && !_isJumping){
        _frame += 0.09;
        _sprite.setTextureRect({0 + (int)_frame * 195, 0, 195, 195});
        if(_frame >= 5) _frame=0;
    }

    ///pj - izquierda
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        _frame += 0.2;
        _velocity.x = -4;
        _sprite.setTextureRect({0 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame=0;
    }

    ///pj - derecha
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        _frame += 0.2;
        _velocity.x = 4;
        _sprite.setTextureRect({0 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame=0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !_isJumping){
        _velocity.y=_jumpVelocity;
        _isJumping=true;
    }

    if(_isJumping){
        _velocity.y += _gravity;
        _sprite.setTextureRect({0, 1170, 195, 195});
    }
    else{
        _velocity.y += _gravity;
    }

    ///espada
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !_isJumping){
        if (!_ban) _ban=true;
        e_hitbox.setPosition(-50, -50);
    }

    if(_ban){
        _frame2 += 0.15;
        if (_sprite.getScale().x == -1 && _frame2 > 2){
            e_hitbox.setPosition(_sprite.getGlobalBounds().left + 40, _sprite.getGlobalBounds().top + 60);
        }
        else if(_frame2 > 2){
            e_hitbox.setPosition(m_hitbox.getGlobalBounds().left + 55, _sprite.getGlobalBounds().top + 60);
        }

        _velocity={0, 0};
        _sprite.setTextureRect({0 + (int)_frame2 * 195, 390, 195, 195});

        if(_frame2 >= 6){
            _frame2 = 0;
            _ban=false;
        }
    }

    _sprite.move(0, _velocity.y);

    m_hitbox.setPosition(_sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);


    ///colisiones
    if(_objetoMapa.verificarColision(m_hitbox)){

        if(_velocity.y > 0){
            _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - _velocity.y);
            _velocity.y=0;
            _isJumping=false;
        }
        else if(_velocity.y < 0){
            _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - _velocity.y);
            _velocity.y = 0;
            _sprite.setTextureRect({0, 1170, 195, 195});
        }
        else{
            _sprite.setTextureRect({0, 1170, 195, 195});
        }
    }

    _sprite.move(_velocity.x, 0);

    m_hitbox.setPosition(_sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);

    if (_objetoMapa.verificarColision(m_hitbox)) {
        if (_velocity.x != 0) {
            _sprite.move(-_velocity.x, 0);
            _velocity.x = 0;
        }
    }

    ///barra de vida
    m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    _bVida.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 50);

    ///actualizacion de la barra de vida
    if(_vida < 51){
        _bVida.setFillColor(sf::Color::Red);//(---)
    }
    else{
        _bVida.setFillColor(sf::Color::Green);//(+++)
    }

    if(_velocity.x < 0){
        _sprite.setScale(-1, 1);
    }
    else if(_velocity.x > 0){
        _sprite.setScale(1, 1);
    }

    if(m_hitbox.getGlobalBounds().left < 0){
        _sprite.setPosition(_sprite.getPosition().x + 4, _sprite.getPosition().y);
        m_hitbox.setPosition(m_hitbox.getPosition().x - _velocity.x, m_hitbox.getPosition().y);
    }
    if(m_hitbox.getGlobalBounds().left + 50 > 1600){
        _sprite.setPosition(_sprite.getPosition().x - 4, _sprite.getPosition().y);
        m_hitbox.setPosition(m_hitbox.getPosition().x - _velocity.x, m_hitbox.getPosition().y);
    }
    if(m_hitbox.getGlobalBounds().top < 0){
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y + 4);
    }
    if(m_hitbox.getGlobalBounds().top + m_hitbox.getGlobalBounds().height > 600){
        muerte();
    }
}

bool pj::isAlive(){

    if(_vida>0){
        return true;
    } else{
        return false;
    }
}

void pj::danioRecibido(int danio){

    _frame4 += 0.1f;
    _sprite.setTextureRect({0 + (int)_frame4 * 195, 1170, 195, 195});
    if (_frame4 >= 4) {
        _frame4 = 0;
        _vida = _vida - danio;
    }
}

void pj::draw(sf::RenderTarget& target, sf::RenderStates state) const{

    target.draw(m_hitbox, state);
    target.draw(_sprite, state);
    target.draw(_bVida);

    if(_ban){
        target.draw(e_hitbox, state);
    }
}

bool pj::getBan(){return _ban;}
void pj::curar(int cant){_vida = _vida + cant;}
float pj::getPositionX(){return _sprite.getPosition().x;}
float pj::getPositionY(){return m_hitbox.getPosition().y;}

void pj::muerte(){

    _frame3 += 0.15;
    _velocity = {0, 0};
    _sprite.setTextureRect({0 + (int)_frame3 * 195, 1560, 195, 195});

    if(_frame3 >= 4){
        _frame3 = 0;
        m_hitbox.setPosition(0, 0);
        _sprite.setPosition(0, 0);
        _vida = 100;
    }
}

sf::RectangleShape pj::getHitbox() const{return m_hitbox;}
sf::RectangleShape pj::getHitboxE(){return e_hitbox;}

void pj::respawn(){

    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width,
                        std::rand() % 500 + _sprite.getGlobalBounds().height);

    m_hitbox.setPosition(_sprite.getGlobalBounds().left, _sprite.getGlobalBounds().top);
}
