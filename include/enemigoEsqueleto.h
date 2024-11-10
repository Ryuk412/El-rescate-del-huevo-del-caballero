#ifndef ENEMIGOESQUELETO_H_INCLUDED
#define ENEMIGOESQUELETO_H_INCLUDED
#include "inc.h"

class enemigoEsqueleto:  public sf::Drawable, public colisionable{

public:

    enemigoEsqueleto();
    void update(int limitA, int limitB);
    void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
    sf::RectangleShape getHitbox()const override;
    void respawn();
    void muerte();
    bool isAlive();
    void danioRecibido(int danio);
    void setSpritePosition(int posicionX, int posicionY);

private:

    sf::RectangleShape esq_hitbox;
    int _direccion=-1;
    sf::Sprite esq_sprite;
    sf::Texture _textureEsq;
    sf::Vector2f esq_velocity={0,0};
    float _frame=0;
    float _frame2=0;
    int esq_vida;
};

#endif // ENEMIGOESQUELETO_H_INCLUDED
