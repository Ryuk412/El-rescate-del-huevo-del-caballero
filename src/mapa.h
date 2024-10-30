#ifndef MAPA_H
#define MAPA_H
#include "inc.h"


class mapa {
public:
    // Constructor que carga el mapa y los tiles
    mapa(const std::string& archivoMapa, const std::string& archivoTileset);

    // Método para dibujar el mapa en la ventana de SFML
    void dibujar(sf::RenderWindow& ventana);

private:
    sf::Texture tilesetTexture;        // Textura del tileset
    std::vector<sf::Sprite> tiles;     // Vector de sprites para cada tile
    sf::Vector2u tileSize;             // Tamaño de cada tile
    sf::Vector2u mapaDimensiones;      // Dimensiones del mapa en tiles

    void cargarMapa(const std::string& archivoMapa); // Método para cargar el mapa desde TMX
};

#endif // MAPA_H
