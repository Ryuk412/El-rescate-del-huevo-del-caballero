#ifndef JEFE_H
#define JEFE_H
#include "inc.h"
class Jefe : public sf::Drawable, public colisionable
{
    public:
        Jefe();
    void update(mapa& _objetoMapa);

       void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
   sf::RectangleShape getHitbox()const override;
    bool isAlive();
    void muerte();
    void danioRecivido(int danio);
    void ataque();
    void setSpritePosition(float x,float y);


    private:

        sf::RectangleShape j_hitbox;
        sf::RectangleShape _hitbox;
        sf::Sprite j_sprite;
        sf::Texture j_texture;
        sf::Vector2f j_velocity={};
        int _direccion=-1;
        float  _frame=0;
        float _frame2=0;
        float _frame3=0;
        float _frame4=0;
        float j_vida;
};

#endif // JEFE_H
