#include "Opciones.h"
#include "ArchivoJugadores.h"
#include <iostream>
using namespace std;

void opcionesMenu(sf::RenderWindow& window){

    Boton comoJugar(240, 225, 320, 70, "CÓMO JUGAR");
    Boton eliminarPartidas(240, 310, 320, 70, "ELIMINAR PARTIDAS");
    Boton volver(363, 463, 70, 20, " ");

    sf::Texture opcionesTextura;
    if(!opcionesTextura.loadFromFile("menu/opciones.png")){return;}

    sf::Texture comoJugarTextura;
    if(!comoJugarTextura.loadFromFile("menu/como_jugar.png")){return;}

    bool comoJugarMenu=0;
    ArchivoJugadores archivo;

    while (window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed){

                if(volver.MouseClick(window)){
                    if(comoJugarMenu){comoJugarMenu=0;}
                    else{return;}
                }

                if(comoJugar.MouseClick(window)){comoJugarMenu=1;}

                if(eliminarPartidas.MouseClick(window)){archivo.vaciar();}

            }
        }

        window.clear();

        if(comoJugarMenu){
            sf::Sprite comoJugarSprite(comoJugarTextura);
            window.draw(comoJugarSprite);
            volver.draw(window);
        }
        else{
            sf::Sprite sprite(opcionesTextura);
            window.draw(sprite);
            comoJugar.draw(window);
            eliminarPartidas.draw(window);
            volver.draw(window);

        }
        window.display();
    }
}
