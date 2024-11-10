#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int menu(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rescate magico: El rescate del huevo del caballero");

    Boton menu1(290, 235, 220, 70, "JUGAR");
    Boton menu2(290, 320, 220, 70, "OPCIONES");
    Boton menu3(290, 410, 220, 70, "CREDITOS");
    Boton menu4(290, 495, 220, 70, "SALIR");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/menu.png")){return -1;}

    sf::Music musica;
    if (!musica.openFromFile("menu/musica/musica_menu.mp3")){return -2;}
    musica.setLoop(true);
    musica.play();

    bool enJugar=0;
    bool enOpciones=0;
    bool enCreditos=0;

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                    window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed){

                if (menu1.MouseClick(window)){enJugar=1;}
                if (menu2.MouseClick(window)){enOpciones=1;}
                if (menu3.MouseClick(window)){enCreditos=1;}

                if (menu4.MouseClick(window)){
                        musica.stop();
                        return 0;}
            }
        }
        window.clear();

        if(enJugar){
            jugarMenu(window);
            enJugar=0;
        }
        if(enOpciones){
            opcionesMenu(window);
            enOpciones=0;
        }
        if(enCreditos){
            creditosMenu(window);
            enCreditos=0;
        }

        sf::Sprite sprite(texture);
        window.draw(sprite);
        menu1.draw(window);
        menu2.draw(window);
        menu3.draw(window);
        menu4.draw(window);

        window.display();
    }

    return 0;
}

