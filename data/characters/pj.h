#ifndef PJ_H
#define PJ_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class pj: public sf::Drawable
{
    public:
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        pj();
        virtual ~pj();

    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _textureM;
        float _velocity;
};

#endif // PJ_H
