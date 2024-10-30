#include "mapa.h"
#include <iostream>

// Implementación del constructor
mapa::mapa(const std::string& archivoMapa) {
    // Cargar la textura del tileset
    if (!_mapa.loadFromFile(archivoMapa)) {
        std::cerr << "Error al cargar el archivo del Mapa" << std::endl;
    }

    // Inicializar el VertexArray con LineStrip y 5 vértices
    _hitbox.setPrimitiveType(sf::LineStrip);
    _hitbox.resize(5); // 5 vértices para cerrar el rectángulo

    cargarMapa();
    cargarEstructura();
}

// Implementación del método para cargar el mapa
void mapa::cargarMapa() {
    _Smapa.setTexture(_mapa);
}

// Implementación del método para configurar la estructura de la hitbox
bool mapa::cargarEstructura() {
    // Definir las posiciones de los vértices
    _hitbox[0].position = sf::Vector2f(0.0f, 141.0f);
    _hitbox[1].position = sf::Vector2f(360.0f, 141.0f);
    _hitbox[2].position = sf::Vector2f(360.0f, 325.0f);
    _hitbox[3].position = sf::Vector2f(0.0f, 250.0f);
    _hitbox[4].position = sf::Vector2f(0.0f, 200.0f); // Cerrar el rectángulo

    // Asignar color rojo a cada vértice
    for (int i = 0; i < 5; ++i) {
        _hitbox[i].color = sf::Color::Red;
    }

    return true;
}

// Función para verificar si un punto está cerca de una línea definida por dos vértices
    bool mapa::puntoCercaDeLinea(const sf::RectangleShape& p, const sf::Vector2f& a, const sf::Vector2f& b, float tolerancia) {
    float longitudAB = std::hypot(b.x - a.x, b.y - a.y);
    float distancia = std::abs((b.y - a.y) * p.getPosition().x - (b.x - a.x) * p.getPosition().y + b.x * a.y - b.y * a.x) / longitudAB;

    return distancia <= tolerancia;
}
// Función para verificar si un punto está cerca de cualquier segmento del VertexArray
bool mapa::colisionaConVertexArray(const sf::RectangleShape& punto, float tolerancia) {
    for (size_t i = 0; i < _hitbox.getVertexCount(); ++i) {
        sf::Vector2f a = _hitbox[i].position;
        sf::Vector2f b = _hitbox[(i + 1) % _hitbox.getVertexCount()].position; // Se conecta al primer vértice si es el último

        if (puntoCercaDeLinea(punto, a, b, tolerancia)) {
            return true;
        }
    }
    return false;
}


// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {
    // Dibujar mapa
     ventana.draw(_Smapa);

    // Dibujar la hitbox
    ventana.draw(_hitbox);
}
