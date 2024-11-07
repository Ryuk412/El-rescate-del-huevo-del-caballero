#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace std;

int main(){

    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Rescate m�gico: El rescate del huevo del caballero");
    Menu menuPrincipal(ventana);

    while(ventana.isOpen()){
        sf::Event evento;

        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                ventana.close();
            }

            menuPrincipal.procesarEventoEntrada(evento); ///procesa los eventos de entrada del menu
            ventana.clear();
            menuPrincipal.dibujar(ventana);
            ventana.display();
        }

    }
        return 0;
}

