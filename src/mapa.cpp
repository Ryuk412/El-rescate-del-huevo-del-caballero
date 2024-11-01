#include "mapa.h"
#include <iostream>

// Implementación del constructor
mapa::mapa(const std::string& archivoMapa) {
    // Cargar la textura
    if (!_mapa.loadFromFile(archivoMapa)) {
        std::cerr << "Error al cargar el archivo del Mapa" << std::endl;
    }
    // Valor del vector cambiado
    _hitbox.resize(25);
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
      cargarHitbox(4,345.0f,45.0f,449.0f,209.0f);
      cargarHitbox(5,115.0f,13.0f,756.0f,77.0f);
      cargarHitbox(6,11.0f,120.0f,798.0f,90.0f);
      cargarHitbox(7,175.0f,26.0f,799.0f,195.0f);
      cargarHitbox(8,72.0f,34.0f,508.0f,366.0f);
      cargarHitbox(9,72.0f,34.0f,654.0f,366.0f);
      cargarHitbox(10,365.0f,17.0f,325.0f,522.0f);
      cargarHitbox(11,70.0f,39.0f,399.0f,483.0f);
      cargarHitbox(12,199.0f,27.0f,122.0f,557.0f);
      cargarHitbox(13,117.0f,30.0f,2.0f,529.0f);
      cargarHitbox(14,27.0f,113.0f,1.0f,415.0f);
      cargarHitbox(15,53.0f,30.0f,27.0f,415.0f);
      cargarHitbox(16,213.0f,40.0f,694.0f,505.0f);
      cargarHitbox(17,167.0f,40.0f,798.0f,337.0f);
      cargarHitbox(18,71.0f,13.0f,971.0f,194.0f);
      cargarHitbox(19,258.0f,53.0f,1042.0f,194.0f);
      cargarHitbox(20,125.0f,23.0f,1306.0f,234.0f);
      cargarHitbox(21,161.0f,51.0f,1439.0f,195.0f);
      cargarHitbox(22,19.0f,141.0f,912.0f,387.0f);
      cargarHitbox(23,302.0f,22.0f,1038.0f,405.0f);
      cargarHitbox(24,207.0f,131.0f,1393.0f,375.0f);

    return true;
}

bool mapa::cargarHitbox(int vecPos,float w,float h,float x,float y){

    _hitbox[vecPos].setSize({w,h}); // Define el tamaño en pixeles del rectangulo
    _hitbox[vecPos].setPosition({x,y}); // Setea la posicion del rectangulo en la pantalla
    _hitbox[vecPos].setFillColor(sf::Color::Blue); // Para poder ver las hitboxes, borrar despues
    return true;
}

// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {

     ventana.draw(_Smapa); // Dibujar mapa
     dibujarHitbox(ventana); // Llamado al metodo dibujar hitbox
}
    // Metodo para Dibujar la hitbox
void mapa::dibujarHitbox(sf::RenderWindow& ventana){
    for(int j=0; j<25;j++){ // Recorre el vector
    ventana.draw(_hitbox[j]);
     }
}
    // Método para verificar colisiones
bool mapa::verificarColision(const sf::RectangleShape& objeto) {
    for (int i=0;i<50;i++) { // Recorre el vector buscando colision
        if (_hitbox[i].getGlobalBounds().intersects(objeto.getGlobalBounds())) {
            return true; // Colisión detectada
        }
    }
    return false; // No hay colisión
}

