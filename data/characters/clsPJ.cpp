#include <iostream>
#include "pj.h"

// Constructor y Destructor
pj::pj() {
    _textureM.loadFromFile("assets/characters(100x100)/Knight/Knight/Knight.png");
    _sprite.setTexture(_textureM);
    _sprite.setTextureRect({0, 0, 195, 195});
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    m_hitbox.setSize({50, 60});
    m_hitbox.setFillColor(sf::Color::Red);
    e_hitbox.setSize({25, 65});
    e_hitbox.setFillColor(sf::Color::Blue);
    _sprite.setPosition(200, 200);
}

pj::~pj() {}

// Método de actualización del estado del personaje
void pj::update() {
    // Reiniciar velocidad en cada actualización
    _velocity = {0, 0};

    _velocity.y +=3.0f;
    // Animación si el personaje está quieto
    if (_velocity.x == 0) {
        _frame += 0.09;
        _sprite.setTextureRect({0 + (int)_frame * 195, 0, 195, 195});
        if (_frame >= 5) _frame = 0;
    }

    // Movimiento y animación en función de las teclas presionadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _frame += 0.2;
        _velocity.y = -4;
        _sprite.setTextureRect({195 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _frame += 0.2;
        _velocity.x = -4;
        _sprite.setTextureRect({195 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _frame += 0.2;
        _velocity.y = 4;
        _sprite.setTextureRect({195 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _frame += 0.2;
        _velocity.x = 4;
        _sprite.setTextureRect({195 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame = 0;
    }

    // Ataque activado con la tecla Z
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        if (!_ban) _ban = true;
        e_hitbox.setPosition(-50, -50);
    }

    // Animación de ataque
    if (_ban) {
        _frame2 += 0.15;
        if (_sprite.getScale().x == -1 && _frame2 > 2) {
            e_hitbox.setPosition(_sprite.getGlobalBounds().left + 40, _sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            e_hitbox.setPosition(m_hitbox.getGlobalBounds().left + 55, _sprite.getGlobalBounds().top + 60);
        }
        _velocity = {0, 0};
        _sprite.setTextureRect({195 + (int)_frame2 * 195, 390, 195, 195});
        if (_frame2 >= 5) {
            _frame2 = 0;
            _ban = false;
        }
    }

    // Movimiento diagonal ajustado
    if (_velocity.x != 0 && _velocity.y != 0) {
        _velocity.x /= 1.414213562;
        _velocity.y /= 1.414213562;
    }
    _sprite.move(_velocity);

    // Ajuste de dirección del sprite
    if (_velocity.x < 0) _sprite.setScale(-1, 1);
    else if (_velocity.x > 0) _sprite.setScale(1, 1);

    // Actualización de la posición de la hitbox
    m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);

    // Límites de la ventana
    if (m_hitbox.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getPosition().x + 4, _sprite.getPosition().y);
        m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    }
    if (m_hitbox.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y + 4);
        m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    }
    if (m_hitbox.getGlobalBounds().left + m_hitbox.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - 170), _sprite.getPosition().y);
        m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    }
    if (m_hitbox.getGlobalBounds().top + m_hitbox.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - 122));
        m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    }
    if(_colisiionando){
            _velocity.x=0;
            _velocity.y=0;
        _sprite.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);
        m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    }
}

bool pj::getBan(){
    return _ban;
}
// Método para dibujar el personaje y sus hitboxes
void pj::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(m_hitbox, state);
    target.draw(_sprite, state);
    if (_ban) {
        target.draw(e_hitbox, state);
    }
}

// Métodos de obtención de hitboxes
sf::RectangleShape pj::getHitbox() const {
    return m_hitbox;
}

sf::RectangleShape pj::getHitboxE() {
    return e_hitbox;
}

// Método de respawn para reiniciar la posición del personaje
void pj::respawn() {
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width,
                        std::rand() % 500 + _sprite.getGlobalBounds().height);
    m_hitbox.setPosition(_sprite.getGlobalBounds().left, _sprite.getGlobalBounds().top);
}
void pj::setColisionando(bool estado){
    std::cout << "Estado de colisionando: " << _colisiionando << std::endl;

    _colisiionando=estado;
}


