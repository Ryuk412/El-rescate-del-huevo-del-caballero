#ifndef JEFE_H
#define JEFE_H


class Jefe
{
    public:
    Jefe();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
    sf::RectangleShape getHitbox()const override;
    void respawn();
    void muerte();
    bool isAlive();
    void danioRecibido(int danio);

        virtual ~Jefe();

    protected:

    private:
    sf::RectangleShape j_hitbox;
    sf::RectangleShape v_barra;
    int _direccion=-1;
    sf::Sprite e_sprite;
    sf::Texture _textureE;
    sf::Vector2f e_velocity={};
    float _frame=0;
    float _frame2=0;
    float e_vida;

};
#endif // JEFE_H
