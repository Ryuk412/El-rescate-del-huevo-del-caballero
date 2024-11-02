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
    ///mapa mapa("data/maps/nivel1_mapa.png");
    sf::Sprite fondo;
    sf::Texture bg;
    bg.loadFromFile("data/maps/mapaDosTest1.png");
    fondo.setTexture(bg);
    corazon.respawn();
    RenderWindow window(sf::VideoMode(1600, 600), "El rescate del huevo del caballero");
    window.setFramerateLimit(60);

        sf::RectangleShape obj1;
        obj1.setSize({500,600});
        obj1.setFillColor(sf::Color::Magenta);
        obj1.setPosition(10.f,440.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        ejemplo.isGravity(ejemplo,obj1);
        ejemplo.update();//Se actualiza la posicion del personaje
        slime.update();
        if(ejemplo.isCollision(corazon) ) {
            corazon.respawn();
        }
        if(ejemplo.isCollision(slime)){
            ejemplo.respawn();
        }
        if( ejemplo.getHitboxE().getGlobalBounds().intersects(slime.getHitbox().getGlobalBounds()) and ejemplo.getBan()){
            slime.muerte();

        //    slime.respawn();
        }
       /* if(mapa.colisionaConVertexArray(ejemplo.getHitbox(),5.0f)){
        ejemplo.setColisionando(true);
        }else{ejemplo.setColisionando(false);};
        sf::VertexArray obj1(sf::LineStrip, 11);
    obj1[0].position=sf::Vector2f(10.f, 440.f);
    obj1[1].position=sf::Vector2f(40.f, 415.f);
    obj1[2].position=sf::Vector2f(230.f, 415.f);
    obj1[3].position=sf::Vector2f(260.f, 395.f);
    obj1[4].position=sf::Vector2f(440.f, 395.f);
    obj1[5].position=sf::Vector2f(475.f, 420.f);
    obj1[6].position=sf::Vector2f(650.f, 420.f);
    obj1[7].position=sf::Vector2f(675.f, 445.f);
    obj1[8].position=sf::Vector2f(675.f, 535.f);
    obj1[9].position=sf::Vector2f(10.f, 535.f);
    obj1[10].position=sf::Vector2f(10.f, 440.f);
        // Dibujar el mapa
        mapa.dibujar(window);*/

        window.draw(fondo);
        window.draw(obj1);
        window.draw(slime);
        window.draw(ejemplo);//Se dibuja el pesronaje en la pantalla
        window.draw(corazon);//Se dibuja el pesronaje en la pantalla

        window.display();
    }

    return 0;
}
