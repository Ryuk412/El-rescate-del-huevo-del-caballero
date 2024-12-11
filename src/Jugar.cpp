#include "Jugar.h"
#include "Puntajes.h"

void jugarMenu(sf::RenderWindow& window){

    Boton volver(363, 463, 70, 20, " ");
    Boton nuevaPartida(240, 225, 320, 70, "NUEVA PARTIDA");
    Boton puntajes(240, 310, 320, 70, "PUNTAJES");

    sf::Texture texture;
    if(!texture.loadFromFile("menu/jugar.png")){return;}

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                    window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed){

                if (volver.MouseClick(window)){return;}

                if (nuevaPartida.MouseClick(window)){nuevaPartidaMenu(window);}

                if (puntajes.MouseClick(window)){puntajesMenu(window);}
            }
        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        volver.draw(window);
        nuevaPartida.draw(window);
        puntajes.draw(window);
        window.display();
    }
}
