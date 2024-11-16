#include "NuevaPartida.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

void nuevaPartidaMenu(sf::RenderWindow& window){
    Boton volver(363, 463, 70, 20, " ");
    Boton siguiente(646, 490, 60, 55, " ");

    sf::Texture _textura;
    if(!_textura.loadFromFile("menu/nueva_partida.png")){return;}

    sf::Font _fuente;
    if(!_fuente.loadFromFile("menu/fuente/Arimo-Bold.ttf")){return;}

    string _nombreJugador;

    sf::Text _nombreTxt;
    _nombreTxt.setFont(_fuente);
    _nombreTxt.setCharacterSize(35);
    _nombreTxt.setFillColor(sf::Color::White);
    _nombreTxt.setPosition(294, 307);

    Jugador _jugador;


    while (window.isOpen()){
        sf::Event evento;

        while(window.pollEvent(evento)){

            if(evento.type == sf::Event::Closed){
                    window.close();
            }

            if(evento.type == sf::Event::MouseButtonPressed){

                if(volver.MouseClick(window)){
                        return;
                }

                if(siguiente.MouseClick(window)){
                    _jugador.setNombre(_nombreJugador);
                    cout<<"Nombre del jugador: "<<_jugador.getNombre()<<endl;

                    historiaMenu(window);
                }
            }

            if(evento.type == sf::Event::TextEntered){
                if(evento.text.unicode < 128){
                    char character= static_cast<char>(evento.text.unicode);
                    if (character == '\b'){_nombreJugador.pop_back();}
                    else if(_nombreJugador.length() < 10){_nombreJugador += character;}
                    _nombreTxt.setString(_nombreJugador);
                }
            }
        }

        window.clear();
        sf::Sprite sprite(_textura);
        window.draw(sprite);

        window.draw(_nombreTxt);

        volver.draw(window);
        siguiente.draw(window);

        window.display();
    }
}
