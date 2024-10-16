#include<iostream>
#include "pj.h"
sf::FloatRect pj::getBounds()const{
        return _sprite.getGlobalBounds();
}

void pj::update(){

        //Cada vez que se actualiza el personaje, obtiene velocidad 0 en x y 0 en y

        _velocity={0,0};

        if(_velocity.x==0&&_velocity.y==0){
            _frame+=0.09;
            _sprite.setTextureRect({0 + (int)_frame*195 ,0,195,195});//Ancho y Alto del Personaje,70x65.
            if(_frame>=5){
                _frame=0;
            }
        }
        //Si se presiona una tecla, la velocidad cambia a 4 o -4, dependiendo la dirección,
        //Por lo que antes de dibujar el personaje se va a mover de su posicion anterior
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                _frame+=0.2;
                _velocity.y=-4;
                _sprite.setTextureRect({195 + (int)_frame*195 ,195,195,195});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                _frame+=0.2;
                _velocity.x=-4;
                _sprite.setTextureRect({195 + (int)_frame*195 ,195,195,195});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                _frame+=0.2;
                _velocity.y=4;
                _sprite.setTextureRect({195 + (int)_frame*195 ,195,195,195});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                _frame+=0.2;
                _velocity.x=4;
                _sprite.setTextureRect({195 + (int)_frame*195 ,195,195,195});//Ancho y Alto del Personaje,70x65.
                if(_frame>=7){
                _frame=0;
                }
        }
        if(_velocity.x!=0 && _velocity.y!=0){
            _velocity.x=_velocity.x/1.414213562;
            _velocity.y=_velocity.y/1.414213562;
        }
        _sprite.move(_velocity);

        //Estas dos condicionales lo que hacen es verificar si el personaje se esta moviendo
        //Hacia la derecha o hacia la izquierda, para que el sprite mire hacia la misma direccion
        if(_velocity.x < 0){
            _sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta

        }else if(_velocity.x > 0 ){
            _sprite.setScale(1,1);
        }


        //Condicionales para mantener al personaje dentro de la ventana y que no pueda salir
        if(_sprite.getGlobalBounds().left < 0){
            _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
        }
        if(_sprite.getGlobalBounds().top < 0){
            _sprite.setPosition(_sprite.getPosition().x,_sprite.getOrigin().y);
        }
        if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800){
            _sprite.setPosition(800 - (_sprite.getGlobalBounds().width-_sprite.getOrigin().x), _sprite.getPosition().y);
        }
        if(_sprite.getGlobalBounds().top+ _sprite.getGlobalBounds().height > 600){
            _sprite.setPosition(_sprite.getPosition().x,600 +(_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
        }
}

void pj::draw(sf::RenderTarget& target, sf::RenderStates state)const{
        target.draw(_sprite, state);
}


pj::pj()
{
    //Esto es provisional, deberiamos optimizarlo para que podamos elegir cual textura queremos usar
    //Y que solo tengamos que enviar la direccion de la imagen
    _textureM.loadFromFile("assets/characters(100x100)/Knight/Knight/Knight.png");
    _sprite.setTexture(_textureM);
    _sprite.setTextureRect({0,0,195,195});
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);
    //ctor
}

pj::~pj()
{
    //dtor
}
