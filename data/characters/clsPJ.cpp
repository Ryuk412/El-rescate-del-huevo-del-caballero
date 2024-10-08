#include<iostream>
#include "pj.h"
sf::FloatRect pj::getBounds()const{
        return _sprite.getGlobalBounds();
}
void pj::update(){

   sf::Clock clock;
    int _frameWidth = 100;   // Ancho de cada cuadro
    int _frameHeight = 100;  // Altura de cada cuadro
    int _numFrames = 7;      // N�mero total de cuadros en el spritesheet
    int _currentFrame = 0;         // �ndice del cuadro actual
    float _frameDuration = 0.2f;   // Duraci�n de cada cuadro (en segundos)
    float _elapsedTime = 0.0f;     // Tiempo acumulado desde el �ltimo cambio de cuadro
        //Cada vez que se actualiza el personaje, obtiene velocidad 0 en x y 0 en y
        _velocity={0,0};

        //Si se presiona una tecla, la velocidad cambia a 4 o -4, dependiendo la direcci�n,
        //Por lo que antes de dibujar el personaje se va a mover de su posicion anterior
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                _velocity.y=-4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                _velocity.x=-4;

    int _frameWidth = 100;   // Ancho de cada cuadro
    int _frameHeight = 100;  // Altura de cada cuadro
    int _numFrames = 7;      // N�mero total de cuadros en el spritesheet
    int _currentFrame = 0;         // �ndice del cuadro actual
    float _frameDuration = 0.2f;   // Duraci�n de cada cuadro (en segundos)
    float _elapsedTime = 0.0f;     // Tiempo acumulado desde el �ltimo cambio de cuadro

             _textureM.loadFromFile("assets/Characters(100x100)/Knight/Knight/Knight-Walk.png");
   sf::IntRect rect(0, 0, _frameWidth, _frameHeight);
   _sprite.setTextureRect(rect);
    _sprite.setTexture(_textureM);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);
    float deltaTime = clock.restart().asSeconds();
        _elapsedTime += deltaTime;

        // Cambia al siguiente cuadro si ha pasado suficiente tiempo
        if (_elapsedTime >= _frameDuration) {
            _elapsedTime = 0.0f; // Reinicia el tiempo acumulado
            _currentFrame++;     // Pasa al siguiente cuadro

            // Vuelve al primer cuadro si estamos en el �ltimo
            if (_currentFrame >= _numFrames) {
                _currentFrame = 0;
            }

            // Ajusta la parte de la textura que se muestra
            _sprite.setTextureRect(sf::IntRect(_currentFrame * _frameWidth, 0, _frameWidth, _frameHeight));
        }







        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                _velocity.y=4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                _velocity.x=4;
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
<<<<<<< Updated upstream
    _textureM.loadFromFile("data/images/ejemplo.png");
=======
    _textureM.loadFromFile("assets/Characters(100x100)/Knight/Knight/Dylan.png");
    // sf::IntRect rect(0, 0, frameWidth, frameHeight);
    //_sprite.setTextureRect(rect);
>>>>>>> Stashed changes
    _sprite.setTexture(_textureM);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);

    //ctor
}

pj::~pj()
{
    //dtor
}
