#include "Historia.h"
#include "Pausa.h"

void historiaMenu(sf::RenderWindow& window, Jugador& _jugador){
    Boton empezar(273, 496, 255, 30, " ");
    Boton pausa(690, 55, 50, 50, " ");

    sf::Texture texture;
    if (!texture.loadFromFile("menu/historia.png")){return;}

    bool enPausa=0;

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed){

                if (empezar.MouseClick(window)){
                    game juego(window, _jugador);

                    while (juego.isRunning(window)){
                        juego.update(window, _jugador);
                        juego.render(window, _jugador);
                    }
                }

                if(pausa.MouseClick(window)){
                    enPausa=1;

                }
            }

        }

        window.clear();

        if(enPausa){
            pausaMenu(window);
            enPausa=0;
        }

        sf::Sprite sprite(texture);
        window.draw(sprite);
        empezar.draw(window);
        pausa.draw(window);
        window.display();
    }
}
