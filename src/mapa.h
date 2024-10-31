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
    // Método para verificar la colisión con un punto


private:
    sf::Texture _mapa;        // Textura del mapa
    sf::Sprite _Smapa;        // Sprite del mapa
    sf::RectangleShape _hitbox[50];  // Terreno



    void cargarMapa(); // Método para cargar el mapa
};

#endif // MAPA_H
