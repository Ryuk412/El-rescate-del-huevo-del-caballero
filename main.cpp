#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "enemigo.h"
#include <stdlib.h>
#include <iostream>
#include "data/characters/pj.h"
#include "data/etc/Item.h"
using namespace std;
using namespace sf;


int main()
{
    //Borrar despues
   srand((unsigned)time(0));
    //Declaracion objeto "pj"
    enemigo slime;
    pj ejemplo;
    Item corazon;
    sf::Sprite bg;
    sf::Texture Fondo;
    Fondo.loadFromFile("data/maps/8bin_8x55_180330.jpg");
    bg.setTexture(Fondo);
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
        if(ejemplo.isCollision(corazon) ){
            corazon.respawn();
        }
<<<<<<< HEAD
        window.draw(slime);
=======

        window.draw(bg);
>>>>>>> 35b8e594eeb762abe7d3d2605f3cf49e00414b94
        window.draw(ejemplo);//Se dibuja el pesronaje en la pantalla
        window.draw(corazon);//Se dibuja el pesronaje en la pantalla

        window.display();
    }

    return 0;
}
