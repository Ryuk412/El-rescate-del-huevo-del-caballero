#ifndef PJ_H
#define PJ_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "colisionable.h"
class pj: public sf::Drawable, public colisionable
//Si una clase se va a mostrar en pantalla, se debe heredar el metodo DRAW de la clase Drawable
{
    public:

        void update();//Metodo para actualizar la posicion del personaje
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;//Dibuja al personaje
        sf::FloatRect getBounds()const override;
        pj();
        virtual ~pj();

    protected:

    private:
        sf::Clock clock;
        int _frameWidth = 100;   // Ancho de cada cuadro
        int _frameHeight = 100;  // Altura de cada cuadro
        int _numFrames = 6;      // Número total de cuadros en el spritesheet
        int _currentFrame = 0;         // Índice del cuadro actual
        float _frameDuration = 0.5f;   // Duración de cada cuadro (en segundos)
        float _elapsedTime = 0.0f;
        sf::IntRect _rect;
        sf::Sprite _sprite;
        sf::Texture _textureM;
        sf::Vector2f _velocity={};//Vector de 2 posiciones que define la velocidad en pixeles que tiene el personaje en X e Y
};

#endif // PJ_H
