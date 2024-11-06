#include "musica.h"
#include <iostream>
using namespace std;

Musica::Musica(){ /// carga la musica
    if(_musica.openFromFile("menu/musica/musica_menu.mp3")){
        _musica.setLoop(true); /// repite la musica x buble -> while(true)
    }
    else{cout<<"Error en la carga de la musica de fondo"<<endl;}

    /// hitbox para el icono de la musica
    _musicaHitbox.setSize(sf::Vector2f(50, 50));
    _musicaHitbox.setPosition(35, 500);
    _musicaHitbox.setFillColor(sf::Color::Transparent);
}

void Musica::reproducir(){_musica.play();}  /// reproduce la musica
void Musica::pausar(){_musica.pause();}     /// si se esta reprodciendo la musica, la pausa
void Musica::detener(){_musica.stop();}     /// cierra por completo la reproduccion de la musica


/** maneja los eventos de cuando el usuario hace clic sobre la hitbox rodea al icono de musica que esta en el menu principal*/
void Musica::procesarEventoEntrada(sf::Event &evento) {

    ///si el evento es de tipo click del mouse
    if (evento.type == sf::Event::MouseButtonPressed){

        ///verifica si el click del mouse esta sobre los limites de la hitbox de musica
        if (_musicaHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
            if (_musica.getStatus() == sf::Music::Playing){
                pausar();
            }
            else{
                reproducir();
            }
        }
    }
}

void Musica::dibujar(sf::RenderWindow &ventana){ventana.draw(_musicaHitbox);} /// lo dibuja en la ventana principal (800x600px)
