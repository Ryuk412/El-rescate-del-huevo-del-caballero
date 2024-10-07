#ifndef PJ_H
#define PJ_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class pj: public sf::Drawable
//Si una clase se va a mostrar en pantalla, se debe heredar el metodo DRAW de la clase Drawable
{
    public:
        void update();//Metodo para actualizar la posicion del personaje
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;//Dibuja al personaje
        pj();
        virtual ~pj();

    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _textureM;
        sf::Vector2f _velocity={};//Vector de 2 posiciones que define la velocidad en pixeles que tiene el personaje en X e Y
};

#endif // PJ_H
