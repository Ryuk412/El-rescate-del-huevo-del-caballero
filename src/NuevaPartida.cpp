#include "NuevaPartida.h"
#include <iostream>
using namespace std;

void nuevaPartidaMenu(sf::RenderWindow& window){
    Boton volver(290, 440, 227, 70, " ");
    Boton siguiente(400, 440, 227, 70, "SIGUIENTE");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/nueva_partida.png")){return;}

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (volver.MouseClick(window)){return;}

                if(siguiente.MouseClick(window)){
                        cout<<"Historia"<<endl;
                        historiaMenu(window);
                   }

            }
        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        volver.draw(window);
        siguiente.draw(window);

        window.display();
    }
}
