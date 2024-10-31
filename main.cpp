#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "enemigo.h"
#include <stdlib.h>
#include <iostream>
#include "data/characters/pj.h"
#include "data/etc/Item.h"
#include "src/mapa.h"
using namespace std;
using namespace sf;


int main()
{
    //Declaracion objeto "pj"
    enemigo slime;
    pj ejemplo;
    Item corazon;
    // Crear el mapa usando el archivo TMX y el tileset
    mapa mapa("data/maps/nivel1_mapa.png");
    corazon.respawn();
    RenderWindow window(sf::VideoMode(800, 600), "El rescate del huevo del caballero");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        ejemplo.update();//Se actualiza la posicion del personaje
        slime.update();
        if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.respawn();
        }
        if(ejemplo.isCollision(slime)){
            if(ejemplo.isAlive()==false){
                ejemplo.muerte();
            }else{ejemplo.danioRecibido(25);}
        }
        if( ejemplo.getHitboxE().getGlobalBounds().intersects(slime.getHitbox().getGlobalBounds()) and ejemplo.getBan()){
            if(slime.isAlive()==false){
                slime.muerte();
            }else{slime.danioRecibido(25);}


        }

        // Dibujar el mapa
        mapa.dibujar(window);
        window.draw(slime);
        window.draw(ejemplo);//Se dibuja el pesronaje en la pantalla
        window.draw(corazon);//Se dibuja el pesronaje en la pantalla

        window.display();
    }

    return 0;
}
