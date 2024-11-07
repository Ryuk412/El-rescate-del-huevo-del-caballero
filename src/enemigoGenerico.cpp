#include "enemigoGenerico.h"

enemigoGenerico::enemigoGenerico(){}

void enemigoGenerico::setEnemies(){
    //El punto en el que inicia cada enemigo.
    //Esta funcion se ejecuta una sola vez.
    slime.resize(5);
    slime[0].setSpritePosition(10,200,10,380);
    slime[1].setSpritePosition(440,250,440,620);
    slime[2].setSpritePosition(1050,450,1050,1200);
    slime[3].setSpritePosition(900,250,900,1200);
    slime[4].setSpritePosition(450,580,450,700);
    osomaloso.resize(1);
    osomaloso[0].setSpritePosition(1200,250,1150,1350);

}

void enemigoGenerico::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
    for(int i=0;i<5;i++){
        target.draw(slime[i]);
        }
    target.draw(osomaloso[0]);
}

void enemigoGenerico::updateEnemies(pj& ejemplo){
    //El update de cada enemigo se ejecuta en una funcion aparte para que update() quede mas limpio.
    for(int i=0;i<slime.size();i++){
        slime[i].update();
        }
    osomaloso[0].update(ejemplo);
}

bool enemigoGenerico::verificarColisionEspada(pj& p,sf::RectangleShape hitbox) {

    for (int i = 0; i < slime.size(); i++) {
        if (slime[i].getHitbox().getGlobalBounds().intersects(hitbox.getGlobalBounds())&&p.getBan()) {
            if(slime[i].isAlive()==false){
                slime[i].muerte();
            }
            if(p.getBan()){
            slime[i].danioRecibido(25); // Aplica daño al slime si es necesario
            return true; // Devuelve true si encuentra una colisión con algún slime
            }

        }
    }
    return false; // Si no hay colisión con ningún slime, devuelve false
}

bool enemigoGenerico::verificarColisionEnemigo(sf::RectangleShape hitbox){
    for(int i=0;i<5;i++){
    if(slime[i].getHitbox().getGlobalBounds().intersects(hitbox.getGlobalBounds())&&slime[i].isAlive()){

            return true;
    }

    }
    return false;
}


int enemigoGenerico::getContador(){
    return contador;
}
