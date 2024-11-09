#include "Opciones.h"

#include <iostream>
using namespace std;

void opcionesMenu(sf::RenderWindow& window){

    Boton comoJugar(290, 225, 220, 70, "CÓMO JUGAR");
    Boton eliminarPartidas(290, 310, 220, 70, "ELIMINAR PARTIDAS");
    Boton volver(290, 440, 220, 70, " ");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/opciones.png")){return;}

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {

                if (volver.MouseClick(window)){return;}

                if (comoJugar.MouseClick(window)) {
                    cout << "Mostrar tutorial de cómo jugar" << endl;
                    // Aquí puedes agregar la lógica para mostrar el tutorial de cómo jugar
                }
                if (eliminarPartidas.MouseClick(window)) {
                    cout << "Eliminar partidas guardadas" << endl;
                    // Aquí puedes agregar la lógica para eliminar las partidas guardadas
                }

            }
        }
        window.clear();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        comoJugar.draw(window);
        eliminarPartidas.draw(window);
        volver.draw(window);
        window.display();
    }
}
