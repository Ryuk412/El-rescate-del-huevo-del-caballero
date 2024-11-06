#include "Jefe.h"
#include "inc.h"


Jefe::Jefe()
{

    _textureE.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
    e_sprite.setTexture(_textureE);
    e_sprite.setTextureRect({0,0,130,130});
    e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
    j_hitbox.setSize({60,30});
    j_hitbox.setFillColor(sf::Color::Yellow);
    e_sprite.setPosition(500,600);
    e_vida=50;
    v_barra.setSize({e_vida,10});
    v_barra.setFillColor(sf::Color::Green);

}
void Jefe::respawn(){
    e_sprite.setPosition(std::rand()%700+e_sprite.getGlobalBounds().width,std::rand() % 500+e_sprite.getGlobalBounds().height);
    j_hitbox.setPosition(e_sprite.getGlobalBounds().left, e_sprite.getGlobalBounds().top);
}
 void Jefe::muerte(){



        _frame2 += 0.15;
        if (e_sprite.getScale().x == -4 && _frame2 > 2) {
            j_hitbox.setPosition(e_sprite.getGlobalBounds().left + 40, e_sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            j_hitbox.setPosition(j_hitbox.getGlobalBounds().left + 55, e_sprite.getGlobalBounds().top + 60);
        }
        e_velocity = {0, 0};
        e_sprite.setTextureRect({139 + (int)_frame2 * 130, 390, 130, 130});
        if (_frame2 >= 4) {
            _frame2 = 0;
        j_hitbox.setPosition(-50, -50);
        e_sprite.setPosition(-50,-50);
        }




    }

 bool Jefe::isAlive(){
 if(e_vida > 0  ){ return true;   }
 else{return false;    }




 }
    void Jefe::danioRecibido(int danio){

    e_vida=e_vida-danio;


    }



void Jefe::update()
{
    bool ban=true;
    e_velocity= {};




    if(e_velocity.x==0&&e_velocity.y==0)
    {
        _frame+=0.009;
        e_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4)
        {
            _frame=0;
        }
    }



    if(e_velocity.x==0&&e_velocity.y==0 )
    {



        _frame+=0.2;
        e_velocity.x=-2 * _direccion;
        e_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }

    if(j_hitbox.getGlobalBounds().left < 0   )
    {

        e_sprite.setPosition(e_sprite.getPosition().x + 4, e_sprite.getPosition().y);
        j_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (j_hitbox.getGlobalBounds().left + j_hitbox.getGlobalBounds().width > 800)
    {
        e_sprite.setPosition(800 - (e_sprite.getGlobalBounds().width - 103), e_sprite.getPosition().y);
        j_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;

    }


    if(e_velocity.x < 0)
    {
        e_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(e_velocity.x > 0 )
    {
        e_sprite.setScale(1,1);
    }


    e_sprite.move(e_velocity);



    j_hitbox.setPosition( e_sprite.getGlobalBounds().left + 30, e_sprite.getGlobalBounds().top + 50 );



}
sf::RectangleShape Jefe::getHitbox()
{

    return j_hitbox;

}

void Jefe::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(j_hitbox, state);
    target.draw(e_sprite, state);
}
