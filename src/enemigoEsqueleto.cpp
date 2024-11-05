#include <iostream>
#include "enemigoEsqueleto.h"


enemigoEsqueleto::enemigoEsqueleto()
{

    _textureEsq.loadFromFile("assets/Characters(100x100)/Armored Skeleton/Armored Skeleton/Armored Skeleton.png");
    esq_sprite.setTexture(_textureEsq);
    esq_sprite.setTextureRect({0,0,130,130});
    esq_sprite.setOrigin(esq_sprite.getGlobalBounds().width/2, esq_sprite.getGlobalBounds().height);
    esq_hitbox.setSize({60,30});
    esq_hitbox.setFillColor(sf::Color::Yellow);
    esq_vida=50;


}
void enemigoEsqueleto::respawn(){
    esq_sprite.setPosition(std::rand()%700+esq_sprite.getGlobalBounds().width,std::rand() % 500+esq_sprite.getGlobalBounds().height);
    esq_hitbox.setPosition(esq_sprite.getGlobalBounds().left, esq_sprite.getGlobalBounds().top);
}

 void enemigoEsqueleto::muerte(){



        _frame2 += 0.15;
        if (esq_sprite.getScale().x == -4 && _frame2 > 2) {
            esq_hitbox.setPosition(esq_sprite.getGlobalBounds().left + 40, esq_sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            esq_hitbox.setPosition(esq_hitbox.getGlobalBounds().left + 55, esq_sprite.getGlobalBounds().top + 60);
        }
        esq_velocity = {0, 0};
        esq_sprite.setTextureRect({139 + (int)_frame2 * 130, 390, 130, 130});
        if (_frame2 >= 4) {
            _frame2 = 0;
        esq_hitbox.setPosition(-50, -50);
        esq_sprite.setPosition(-50,-50);
        }




    }

 bool enemigoEsqueleto::isAlive(){
 if(esq_vida > 0  ){ return true;   }
 else{return false;    }




 }
    void enemigoEsqueleto::danioRecibido(int danio){

    esq_vida=esq_vida-danio;


    }



void enemigoEsqueleto::update(int limitA, int limitB)
{
    bool ban=true;
    esq_velocity= {};




    if(esq_velocity.x==0&&esq_velocity.y==0)
    {
        _frame+=0.009;
        esq_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4)
        {
            _frame=0;
        }
    }



    if(esq_velocity.x==0&&esq_velocity.y==0 )
    {



        _frame+=0.2;
        esq_velocity.x=-2 * _direccion;
        esq_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }

    if(esq_hitbox.getGlobalBounds().left < limitA)
    {

        esq_sprite.setPosition(esq_sprite.getPosition().x + 4, esq_sprite.getPosition().y);
        esq_hitbox.setPosition(5 + esq_sprite.getGlobalBounds().left + 66, esq_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (esq_hitbox.getGlobalBounds().left + esq_hitbox.getGlobalBounds().width > limitB)
    {
        esq_sprite.setPosition(limitB - (esq_sprite.getGlobalBounds().width - 103), esq_sprite.getPosition().y);
        esq_hitbox.setPosition(5 + esq_sprite.getGlobalBounds().left + 66, esq_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;
    }


    if(esq_velocity.x < 0)
    {
        esq_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(esq_velocity.x > 0 )
    {
        esq_sprite.setScale(1,1);
    }


    esq_sprite.move(esq_velocity);



    esq_hitbox.setPosition( esq_sprite.getGlobalBounds().left + 30, esq_sprite.getGlobalBounds().top + 50 );



}
sf::RectangleShape enemigoEsqueleto::getHitbox()const
{
    return esq_hitbox;
}

void enemigoEsqueleto::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
    target.draw(esq_hitbox);
    target.draw(esq_sprite);
}



void enemigoEsqueleto::setSpritePosition(int posicionX, int posicionY){
    esq_sprite.setPosition(posicionX,posicionY);
}
