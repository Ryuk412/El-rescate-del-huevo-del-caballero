#ifndef JEFE_H
#define JEFE_H
#include "inc.h"
class Jefe : public sf::Drawable
{
    public:
        Jefe();
    void update(int LimiteA, int LimiteB );

       void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
//    sf::RectangleShape getHitbox()const override;
    bool isAlive();
    void muerte();
    void danioRecivido(int danio);


    private:

        sf::RectangleShape j_hitbox;
        sf::RectangleShape _hitbox;
        sf::Sprite j_sprite;
        sf::Texture j_texture;
        sf::Vector2f j_velocity={};
        int _direccion=-1;
        float  _frame=0;
        float j_vida;
};

#endif // JEFE_H
