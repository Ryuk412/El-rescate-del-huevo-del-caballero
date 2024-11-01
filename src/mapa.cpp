#include "mapa.h"
#include <iostream>

// Implementación del constructor
mapa::mapa(const std::string& archivoMapa) {
    // Cargar la textura del tileset
    if (!_mapa.loadFromFile(archivoMapa)) {
        std::cerr << "Error al cargar el archivo del Mapa" << std::endl;
    }

    _hitbox.resize(50);
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
      cargarHitbox(0,365.0f, 75.0f, 0.0f, 146.0f);
      cargarHitbox(1,48.0f,101.0f,310.0f,221.0f);
      cargarHitbox(2,238.0f,38.0f,102.0f,326.0f);
      cargarHitbox(3,75.0f,88.0f,341.0f,325.0f);

    return true;
}

bool mapa::cargarHitbox(int vecPos,float w,float h,float x,float y){
    _hitbox[vecPos].setSize({w,h});
    _hitbox[vecPos].setPosition({x,y});
    // Para poder ver las hitboxes, borrar despues
    _hitbox[vecPos].setFillColor(sf::Color::Blue);
    return true;
}

// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {
    // Dibujar mapa
     ventana.draw(_Smapa);
     dibujarHitbox(ventana);
}
    // Dibujar la hitbox
void mapa::dibujarHitbox(sf::RenderWindow& ventana){
    for(int j=0; j<50;j++){
    ventana.draw(_hitbox[j]);
     }
}
    // Método para verificar colisiones
bool mapa::verificarColision(const sf::RectangleShape& objeto) {
    for (int i=0;i<50;i++) {
        if (_hitbox[i].getGlobalBounds().intersects(objeto.getGlobalBounds())) {
            return true; // Colisión detectada
        }
    }
    return false; // No hay colisión
}

