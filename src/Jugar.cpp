#include "Jugar.h"
#include <iostream>
using namespace std;

void jugarMenu(sf::RenderWindow& window){

    Boton volver(290, 440, 227, 70, " ");
    Boton nuevaPartida(290, 230, 220, 70, "NUEVA PARTIDA");
    Boton cargarPartida(290, 310, 220, 70, "CARGAR PARTIDA");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/jugar.png")){
        cout << "error de carga: mapa jugar_menu" << endl;
        return;
    }

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){

                if (volver.MouseClick(window)){return;}

                if (nuevaPartida.MouseClick(window)){
                    cout<<"nva partida"<<endl;
                    nuevaPartidaMenu(window);
                }
                if (cargarPartida.MouseClick(window)){
                    cout<<"cargar partida"<<endl;
                }
            }
        }

        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        volver.draw(window);
        nuevaPartida.draw(window);
        cargarPartida.draw(window);
        window.display();
    }
}
