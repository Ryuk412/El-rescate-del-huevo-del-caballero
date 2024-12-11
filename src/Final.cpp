#include "Final.h"
#include "Menu.h"

void Final::finalMenu(sf::RenderWindow& window){
    Boton empezar(273, 496, 255, 30, " ");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/final.png")){return;}

    bool salirAMenu=0;

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed){
                salirAMenu=1;
                window.close();
            }

        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);

        window.display();

    }

    if(salirAMenu){
        menu();
    }

}
