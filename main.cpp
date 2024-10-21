#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime> //borrar despues
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
    pj ejemplo;
    Item corazon;
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

        if(ejemplo.isCollision(corazon)){
            corazon.respawn();
        }

        window.draw(ejemplo);//Se dibuja el pesronaje en la pantalla
        window.draw(corazon);//Se dibuja el pesronaje en la pantalla

        window.display();
    }

    return 0;
}
