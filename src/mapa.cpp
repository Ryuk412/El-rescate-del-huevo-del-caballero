#include "mapa.h"
#include <iostream>

// Implementación del constructor
mapa::mapa(const std::string& archivoMapa) {
    // Cargar la textura
    if (!_mapa.loadFromFile(archivoMapa)) {
        std::cerr << "Error al cargar el archivo del Mapa" << std::endl;
    }
    // Valor del vector cambiado
    _hitbox.resize(35);
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
    ///posicion del vector, ancho, alto,posicion en x, posicion en y
    cargarHitbox(0,195.0f, 80.0f, 40.0f, 422.0f);
    cargarHitbox(1,40.0f, 10.0f, 265.0f, 415.0f);
    _hitbox[1].setRotation(135.f);
    cargarHitbox(2,180.f,50.f,260.f,395.f);
    cargarHitbox(3,40.0f, 10.0f, 440.0f, 409.0f);
    _hitbox[3].setRotation(45.f);
    cargarHitbox(4,180.f,50.f,465.f,420.f);
    cargarHitbox(5,40.0f, 10.0f, 640.0f, 440.0f);
    _hitbox[5].setRotation(45.f);
    cargarHitbox(6,70.0f, 8.0f, 420.0f, 310.0f);
    cargarHitbox(7,125.0f, 8.0f, 570.0f, 250.0f);
    cargarHitbox(8, 70.0f, 8.0f, 530.0f, 105.0f);
    cargarHitbox(9, 100.0f, 8.0f, 380.0f, 110.0f);
    cargarHitbox(10,35.0f, 10.0f, 475.0f, 125.0f);
    _hitbox[10].setRotation(45.f);
    cargarHitbox(11,20.0f, 10.0f, 355.0f, 90.0f);
    _hitbox[11].setRotation(45.f);
    cargarHitbox(12,100.0f, 10.0f, 260.0f, 90.0f);
    cargarHitbox(13,25.0f, 10.0f, 265.0f, 105.f);
    _hitbox[13].setRotation(135.f);
    cargarHitbox(14,40.0f, 10.0f, 195.0f, 115.0f);
    cargarHitbox(15,25.0f, 10.0f, 195.0f, 120.f);
    _hitbox[15].setRotation(135.f);
    cargarHitbox(16,165.0f, 10.0f, 0.0f, 160.0f);
    cargarHitbox(17,230.0f, 10.0f, 800.0f, 445.0f);
    cargarHitbox(18,30.0f, 10.0f, 810.0f, 450.0f);
    _hitbox[18].setRotation(135.f);
    cargarHitbox(19,100.0f, 10.0f, 1100.0f, 460.0f);
    cargarHitbox(20,30.0f, 10.0f, 1260.0f, 495.0f);
    _hitbox[20].setRotation(135.f);
    cargarHitbox(21,350.0f, 10.0f, 1250.0f, 485.0f);
    cargarHitbox(22,50.0f, 10.0f, 975.0f, 370.0f);
    cargarHitbox(23,70.0f, 10.0f, 970.0f, 370.0f);
    _hitbox[23].setRotation(90.f);
    cargarHitbox(24,20.0f, 10.0f, 1080.0f, 300.0f);
    cargarHitbox(25,70.0f, 1.0f, 1150.0f, 230.0f);
    cargarHitbox(26,70.0f, 5.0f, 1280.0f, 150.0f);
    cargarHitbox(27,50.0f, 5.0f, 1380.0f, 120.0f);
    cargarHitbox(28,20.0f, 5.0f, 1440.0f, 110.0f);
    _hitbox[28].setRotation(135.f);
    cargarHitbox(29,70.0f, 10.0f, 1520.0f, 100.0f);
    _hitbox[29].setRotation(90.f);
    cargarHitbox(30,70.0f, 10.0f, 1520.0f, 90.0f);
    cargarHitbox(31,20.0f, 5.0f, 1440.0f, 110.0f);
    return true;
}

bool mapa::cargarHitbox(int vecPos,float w,float h,float x,float y){

    _hitbox[vecPos].setSize({w,h}); // Define el tamaño en pixeles del rectangulo
    _hitbox[vecPos].setPosition({x,y}); // Setea la posicion del rectangulo en la pantalla
    _hitbox[vecPos].setFillColor(sf::Color::Magenta); // Para poder ver las hitboxes, borrar despues
    return true;
}

// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {

     ventana.draw(_Smapa); // Dibujar mapa
     dibujarHitbox(ventana); // Llamado al metodo dibujar hitbox
}
    // Metodo para Dibujar la hitbox
void mapa::dibujarHitbox(sf::RenderWindow& ventana){
    for(int j=0; j<35;j++){ // Recorre el vector
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


