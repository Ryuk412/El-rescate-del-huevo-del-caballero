#include "Final.h"
#include "Menu.h"

void finalMenu(sf::RenderWindow& window){

    sf::Texture texture;
    if(!texture.loadFromFile("menu/final.png")){return;}

    bool salirAMenu=0;

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    salirAMenu=1;
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
