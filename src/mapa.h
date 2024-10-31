#ifndef MAPA_H
#define MAPA_H
#include "inc.h"


class mapa  {
public:
    // Constructor que carga el mapa
    mapa(const std::string& archivoMapa);

    // Metodo para generar la estructura
    bool cargarEstructura();
    // Método para dibujar el mapa en la ventana de SFML
    void dibujar(sf::RenderWindow& ventana);
    bool puntoCercaDeLinea(const sf::RectangleShape& p, const sf::Vector2f& a, const sf::Vector2f& b, float tolerancia);
    bool colisionaConVertexArray(const sf::RectangleShape& punto, float tolerancia);


private:
    sf::Texture _mapa;        // Textura del mapa
    sf::Sprite _Smapa;        // Sprite del mapa
    sf::VertexArray _hitbox;  // Terreno
    float tolerancia = 5.0f;  // Distancia mínima para considerar colisión


    void cargarMapa(); // Método para cargar el mapa
};

#endif // MAPA_H
