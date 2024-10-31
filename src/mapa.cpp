#include "mapa.h"
#include <iostream>

// Implementación del constructor
mapa::mapa(const std::string& archivoMapa) {
    // Cargar la textura del tileset
    if (!_mapa.loadFromFile(archivoMapa)) {
        std::cerr << "Error al cargar el archivo del Mapa" << std::endl;
    }


    cargarMapa();
    cargarEstructura();
}

// Implementación del método para cargar el mapa
void mapa::cargarMapa() {
    _Smapa.setTexture(_mapa);
}

// Implementación del método para configurar la estructura de la hitbox
bool mapa::cargarEstructura() {
    //Crear la estructura del terreno
    _hitbox[0].setSize({365.0f,75.0f});
    _hitbox[0].setPosition(0.0f,146.0f);



    // Asignar color rojo a cada Hitbox
//    for (int i = 0; i < 14; ++i) {
//        _hitbox[i].setFillColor(sf::Color::Red) ;
//    }
    _hitbox[0].setFillColor(sf::Color::Red);
    for(int j=0;j<50;j++){
    ventana.draw(_hitbox[j]);
    std::cout<< "POSICION "<< j <<" DIBUJADA."<<std::endl;
    }
    return true;
}



// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {
    // Dibujar mapa
     ventana.draw(_Smapa);
    // Dibujar la hitbox


}
