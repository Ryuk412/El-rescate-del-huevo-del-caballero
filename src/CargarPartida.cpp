#include "CargarPartida.h"

void cargarPartidaMenu(sf::RenderWindow& window){
    Boton volver(363, 463, 70, 20, " ");

    sf::Texture _textura;
    if(!_textura.loadFromFile("menu/cargar_partida.png")){return;}

    while(window.isOpen()){
        sf::Event evento;

        while(window.pollEvent(evento)){

            if(evento.type == sf::Event::Closed){
                window.close();
            }

            if(evento.type == sf::Event::MouseButtonPressed){

                if(volver.MouseClick(window)){return;}
            }
        }

        window.clear();

        sf::Sprite sprite(_textura);
        window.draw(sprite);

        volver.draw(window);

        window.display();
    }
}

