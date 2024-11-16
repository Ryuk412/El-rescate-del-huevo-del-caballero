#include "Pausa.h"
#include "Menu.h"

void pausaMenu(sf::RenderWindow& window){
    Boton reanudar(250, 260, 290, 57, " ");
    Boton salir(255, 340, 290, 57, " ");

    sf::Texture texture;
    if(!texture.loadFromFile("menu/pausa_menu.png")){return;}

    bool salirAMenu=0;

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed){

                if(reanudar.MouseClick(window)){
                    return;
                }

                if(salir.MouseClick(window)){
                    salirAMenu=1;
                    window.close();
                }

            }
        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        reanudar.draw(window);
        salir.draw(window);

        window.display();

    }

    if(salirAMenu){
        menu();
    }

}
