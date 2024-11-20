#include "enemigoBase.h"

void enemigoBase::draw(sf::RenderTarget& target, sf::RenderStates state)const{
    target.draw(en_hitbox);
    target.draw(e_sprite);
    target.draw(attackHitbox);
    if(damageFlag){
        target.draw(damageHitbox);
    }
}

void enemigoBase::update(pj ejemplo){
    e_velocity= {};
    if(e_velocity.x==0&&e_velocity.y==0){
        _frame+=0.009;
        e_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4){
            _frame=0;
        }
    }

    if(e_velocity.x==0&&e_velocity.y==0 ){
        _frame+=0.2;
        e_velocity.x=-2 * _direccion;
        e_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6){
            _frame=0;
        }
    }

    if(en_hitbox.getGlobalBounds().left< limitA){
        e_sprite.setPosition(e_sprite.getPosition().x + 4, e_sprite.getPosition().y);
        en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        _direccion=_direccion*-1;
    }

    if (en_hitbox.getGlobalBounds().left + en_hitbox.getGlobalBounds().width> limitB){
        e_sprite.setPosition(limitB - (e_sprite.getGlobalBounds().width - 103), e_sprite.getPosition().y);
        en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);
        _direccion=_direccion*-1;
    }

    if(e_velocity.x< 0){
        e_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
        attackHitbox.setPosition(e_sprite.getGlobalBounds().left+20,e_sprite.getGlobalBounds().top+80);
        damageHitbox.setPosition(e_sprite.getGlobalBounds().left+10,e_sprite.getGlobalBounds().top+80);
    } else if(e_velocity.x> 0 ){
        e_sprite.setScale(1,1);
        attackHitbox.setPosition(e_sprite.getGlobalBounds().left+90,e_sprite.getGlobalBounds().top+80);
        damageHitbox.setPosition(e_sprite.getGlobalBounds().left+100,e_sprite.getGlobalBounds().top+80);
    }

    if (countdown >= 0){
            attack=false;
            _frame2 = 0;
            countdown-=0.1;
    }

    if(attackHitbox.getGlobalBounds().intersects(ejemplo.getHitbox().getGlobalBounds())&&countdown<=0){
        attack=true;
    }

    if(attack==true){
        attackFrames();
    }
    e_sprite.move(e_velocity);

    en_hitbox.setPosition( e_sprite.getGlobalBounds().left + 30, e_sprite.getGlobalBounds().top + 50 );
}

void enemigoBase::setSpritePosition(int posX, int posY, int posA,int posB){
    e_vida=50;
    startInX=posX;
    startInY=posY;
    e_sprite.setPosition(sf::Vector2f(startInX,startInY));
    limitA=posA;
    limitB=posB;
    e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
}

void enemigoBase::muerte(){
        _frame2 += 0.15;
        if (e_sprite.getScale().x == -4 && _frame2 > 2) {
            en_hitbox.setPosition(e_sprite.getGlobalBounds().left + 40, e_sprite.getGlobalBounds().height + 60);
        } else if (_frame2 > 2) {
            en_hitbox.setPosition(en_hitbox.getGlobalBounds().left + 55, e_sprite.getGlobalBounds().height + 60);
        }
        e_velocity = {0, 0};
        e_sprite.setTextureRect({139 + (int)_frame2 * 130, 390, 130, 130});
        if (_frame2 >= 4) {
            _frame2 = 0;
        }
    }

void enemigoBase::respawn(){
    e_sprite.setPosition(sf::Vector2f(startInX,startInY));
    en_hitbox.setPosition(e_sprite.getGlobalBounds().left, e_sprite.getGlobalBounds().top);
}

bool enemigoBase::isAlive(){
    if(e_vida > 0  ) return true;
    else return false;
 }

void enemigoBase::danioRecibido(int danio){
    e_vida=e_vida-danio;
}

void enemigoBase::attackFrames(){
    //Esta funcion será sobre-escrita por cada enemigo que la herede,
    //con el fin de establecer sus propios frames de ataque.
}

float enemigoBase::getVelocityX(){
    return e_velocity.x;
}

sf::RectangleShape enemigoBase::getDamageHitbox(){
    return damageHitbox;
}

int enemigoBase::getDamage(){
    return damage;
}

sf::RectangleShape enemigoBase::getHitbox()const{
    return en_hitbox;
}
