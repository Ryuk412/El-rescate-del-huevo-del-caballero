#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace std;

int main(){

    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Rescate magico: El rescate del huevo del caballero");
    Menu menuPrincipal;

    while(ventana.isOpen()){
        sf::Event evento;

        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){

                ventana.close();
            }
            menuPrincipal.procesarEventoEntrada(evento); /// procesa los eventos que se realizan en el menu
        }                                                /// y los lleva a sus submenus correspondientes
        ventana.clear();
        menuPrincipal.dibujar(ventana);
        ventana.display();
    }
    return 0;
}
