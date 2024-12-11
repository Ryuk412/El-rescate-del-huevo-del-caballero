#include "Final.h"
#include "Menu.h"

void Final::finalMenu(sf::RenderWindow& window) {
    sf::Texture texture;
    if (!texture.loadFromFile("menu/final.png")) {
        return;  // Si no se puede cargar la textura, no se muestra la pantalla final
    }

    bool salirAMenu = false;

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                salirAMenu=true;
                window.close();
            }
        }

        window.setView(window.getDefaultView());
        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        window.display();
    }

    if(salirAMenu){
        menu();
    }
}

