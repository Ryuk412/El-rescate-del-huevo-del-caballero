#include<iostream>
#include "pj.h"
//sf::FloatRect pj::getBounds()const{
//        return _sprite.getGlobalBounds();
//}
sf::RectangleShape pj::getHitbox()const{
    return m_hitbox;
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            _ban=true;
            e_hitbox.setPosition(_sprite.getGlobalBounds().left + 40, _sprite.getGlobalBounds().top + 60);

            _velocity.x=0;
            _velocity.y=0;
            _frame2+=0.15;
            _sprite.setTextureRect({195 + (int)_frame2*195,390,195,195});
            if(_frame2>=5){
                _frame2=5;

            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)==false){

            _frame2=0;
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

        m_hitbox.setPosition(5+_sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);


        //Condicionales para mantener al personaje dentro de la ventana y que no pueda salir
        if(m_hitbox.getGlobalBounds().left < 0){
            _sprite.setPosition(_sprite.getPosition().x+4, _sprite.getPosition().y);
           m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
        }
//M_HITBOX es una propiedad de la clase pj que se encarga de general el cuadrado de la hiybox (xd)

        if(m_hitbox.getGlobalBounds().top < 0){
            _sprite.setPosition(_sprite.getPosition().x,_sprite.getPosition().y+4);
           m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
        }


        if(m_hitbox.getGlobalBounds().left + m_hitbox.getGlobalBounds().width > 800){
           _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - 170),  _sprite.getPosition().y);
            m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
        }


        if(m_hitbox.getGlobalBounds().top + m_hitbox.getGlobalBounds().height > 600){
            _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - 122));
           m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
        }
}


void pj::draw(sf::RenderTarget& target, sf::RenderStates state)const{
        target.draw(m_hitbox,state);
      target.draw(_sprite, state);
      if(_ban==true){
          target.draw(e_hitbox,state);
      }


}


pj::pj()
{
    //Esto es provisional, deberiamos optimizarlo para que podamos elegir cual textura queremos usar
    //Y que solo tengamos que enviar la direccion de la imagen
    _textureM.loadFromFile("assets/characters(100x100)/Knight/Knight/Knight.png");
    _sprite.setTexture(_textureM);
    _sprite.setTextureRect({0,0,195,195});
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);
    m_hitbox.setSize({50,60});
    m_hitbox.setFillColor(sf::Color::Red);
     e_hitbox.setSize({25,65});
    e_hitbox.setFillColor(sf::Color::Blue);
    _sprite.setPosition(400,300);
    //ctor
}

pj::~pj()
{
    //dtor
}
