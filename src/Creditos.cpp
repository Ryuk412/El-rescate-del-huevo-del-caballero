#include "Creditos.h"

#include <iostream>
using namespace std;

void creditosMenu(sf::RenderWindow& window){
    Boton volver(290, 440, 227, 70, " ");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/creditos.png")){return;}

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (volver.MouseClick(window)){return;}
            }
        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        volver.draw(window);

        window.display();
    }
}
