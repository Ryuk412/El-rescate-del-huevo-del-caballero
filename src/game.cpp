#include "game.h"


game::game() :window(sf::VideoMode(800, 600), "El rescate del huevo del caballero",sf::Style::Default), mapaTest("data/maps/nivel2_mapa.png")  {
    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
}

game::~game(){}

const bool game::isRunning() const {

    return window.isOpen();

}

void game::updateEvent(){
    while (window.pollEvent(evento)){
            if (evento.type == sf::Event::Closed){
                window.close();
        }
}
}
//Toda las verificaiones y los updates de cada objeto van acÃ¡
void game::update(){
    updateEvent();
    if(corazon.getActive()==false){
       corazon.respawn();
       corazon.setActive(true);
    }
    ejemplo.update(mapaTest);
    slime.update();
    osomaloso.update();
    // Verificar si el personaje ha pasado el límite para mover la cámara
        if (ejemplo.getPositionX() > limiteCamaraIzq) {
            // Centrar la vista en el personaje solo en el eje horizontal
            camara.setCenter(ejemplo.getPositionX(), camara.getCenter().y);
        } else {
            // Si el personaje está antes del límite, la cámara se queda al inicio
            camara.setCenter(limiteCamaraIzq, camara.getCenter().y);
        }
        if (ejemplo.getPositionX() > limiteCamaraDer && ejemplo.getPositionX() > limiteCamaraIzq) {
            // Si el personaje está antes del límite, la cámara se queda al inicio
            camara.setCenter(limiteCamaraDer, camara.getCenter().y);
        }


    // Actualizar la vista en la ventana
    window.setView(camara);
    if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.setActive(false);
        }
        if(ejemplo.isCollision(slime)){
            if(ejemplo.isAlive()==false){
                ejemplo.muerte();
            }else{ejemplo.danioRecibido(25);
                   //ejemplo.respawn();             }
        }
    }
        if( ejemplo.getHitboxE().getGlobalBounds().intersects(slime.getHitbox().getGlobalBounds()) and ejemplo.getBan()){
            if(slime.isAlive()==false){
                slime.muerte();
            }else{slime.danioRecibido(25);}


        }

}

//Todas las visualizaciones
void game::render(){
        window.clear();
        mapaTest.dibujar(window);
        window.draw(ejemplo);
        window.draw(osomaloso);
        window.draw(slime);
        window.draw(corazon);
        window.display();

}
