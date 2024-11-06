#ifndef JEFE_H
#define JEFE_H

<<<<<<< Updated upstream

class Jefe : public sf::Drawable, public colisionable
=======
class Jefe : public sf::Drawable
>>>>>>> Stashed changes
{
    public:
    void update();
<<<<<<< Updated upstream
    void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
    void isAlive();
=======
       void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
//    sf::RectangleShape getHitbox()const override;
    bool isAlive();
>>>>>>> Stashed changes
    void muerte();
    void danioRecivido(int danio);


    private:
        Jefe();
        sf::RectangleShape j_hitbox;
        sf::RectangleShape _hitbox;
        sf::Sprite j_sprite;
        sf::Texture j_texture;
        sf::Vector2f j_velovity={};
        float j_frame=0;
        float j_vida;






};

#endif // JEFE_H
