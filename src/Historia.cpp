#include "Historia.h"

#include <iostream>
using namespace std;

void historiaMenu(sf::RenderWindow& window){
    Boton empezar(400, 440, 227, 70, "EMPEZAR");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/historia.png")){return;}

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){

                if (empezar.MouseClick(window)){

                    game juego(window);
                    while (juego.isRunning(window)){
                        juego.update(window);
                        juego.render(window);
                    }
                }
            }
        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        empezar.draw(window);

        window.display();
    }
}
