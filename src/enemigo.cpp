#include <iostream>
#include "enemigo.h"


enemigo::enemigo(){
    _textureE.loadFromFile("assets/Characters(100x100)/Slime/Slime/Slime.png");
    e_sprite.setTexture(_textureE);
    e_sprite.setTextureRect({0,0,130,130});
    e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
    en_hitbox.setSize({60,30});
    en_hitbox.setFillColor(sf::Color::Transparent);
    e_vida=50;
    attackHitbox.setSize({10,-30});
    attackHitbox.setFillColor(sf::Color::Transparent);
    damageHitbox.setSize({10,-50});
    damageHitbox.setFillColor(sf::Color::Transparent);
    damage=25;
}

void enemigo::attackFrames(){
        _frame2 += 0.30;
        if (e_sprite.getScale().x == -1 && _frame2 > 2) {
            en_hitbox.setPosition(e_sprite.getGlobalBounds().left + 40, e_sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            en_hitbox.setPosition(en_hitbox.getGlobalBounds().left + 55, e_sprite.getGlobalBounds().top + 60);
        }
        e_velocity = {0, 0};
        e_sprite.setTextureRect({0 + (int)_frame2 * 130, 390, 130, 130});
        if(_frame2>9){
            damageFlag=true;
        }
        if(_frame2>=13){
            _frame2=0;
            countdown=2;
            damageFlag=false;
        }
}

//
//enemigo::~enemigo()
//{
//    //dtor
//}
