#include "enemigo2.h"

enemigo2::enemigo2(){
    _textureE.loadFromFile("assets/Characters(100x100)/Greatsword Skeleton/Greatsword Skeleton/Greatsword Skeleton.png");
    e_sprite.setTexture(_textureE);
    e_sprite.setTextureRect({0,0,130,130});
    e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
    en_hitbox.setSize({60,30});
    en_hitbox.setFillColor(sf::Color::Transparent);
    e_vida=100;
    attackHitbox.setSize({10,-30});
    attackHitbox.setFillColor(sf::Color::Transparent);
    damageHitbox.setSize({20,-50});
    damageHitbox.setFillColor(sf::Color::Transparent);
    damage=40;
}

void enemigo2::attackFrames(){
        _frame2 += 0.30;
        if (e_sprite.getScale().x == -1 && _frame2 > 2) {
            en_hitbox.setPosition(e_sprite.getGlobalBounds().left + 40, e_sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            en_hitbox.setPosition(en_hitbox.getGlobalBounds().left + 55, e_sprite.getGlobalBounds().top + 60);
        }
        e_velocity = {0, 0};
        e_sprite.setTextureRect({0 + (int)_frame2 * 130, 260, 130, 130});
        if(_frame2>=5&&_frame2<=8){
            damageFlag=true;
        }
        if(_frame2>=9){
            damageFlag=false;
            _frame3+=0.30;
            e_sprite.setTextureRect({0 + (int)_frame3 * 130, 390, 130, 130});
            if(_frame3>=6&&_frame3<=9){
                damageFlag=true;
           }
        }
        if(_frame3>=12){
            _frame2=0;
            _frame3=0;
            countdown=2;
            damageFlag=false;
        }

}
