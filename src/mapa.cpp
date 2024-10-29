#include "mapa.h"


// Implementación del constructor
mapa::mapa(const std::string& archivoMapa, const std::string& archivoTileset) {
    // Cargar la textura del tileset
    if (!tilesetTexture.loadFromFile(archivoTileset)) {
        std::cerr << "Error al cargar el archivo del tileset: " << archivoTileset << std::endl;
    }
    // Cargar el mapa
    cargarMapa(archivoMapa);
}

// Implementación del método para cargar el mapa
void mapa::cargarMapa(const std::string& archivoMapa) {
    tmx::Map mapa;
    if (!mapa.load(archivoMapa)) {
        std::cerr << "No se pudo cargar el mapa: " << archivoMapa << std::endl;
        return;
    }

    // Obtener el tamaño del mapa y los tiles
    mapaDimensiones = sf::Vector2u(mapa.getTileCount().x, mapa.getTileCount().y);
    tileSize = sf::Vector2u(mapa.getTileSize().x, mapa.getTileSize().y);

    // Obtener el tileset
    const auto& tilesets = mapa.getTilesets();
    if (tilesets.empty()) {
        std::cerr << "No se encontró ningún tileset en el mapa." << std::endl;
        return;
    }
    const auto& tileset = tilesets[0];

    // Iterar sobre las capas del mapa y cargar los tiles
    for (const auto& capa : mapa.getLayers()) {
        if (capa->getType() == tmx::Layer::Type::Tile) {
            const auto& tileLayer = capa->getLayerAs<tmx::TileLayer>();

            for (unsigned int y = 0; y < mapaDimensiones.y; ++y) {
                for (unsigned int x = 0; x < mapaDimensiones.x; ++x) {
                    int tileID = tileLayer.getTiles()[y * mapaDimensiones.x + x].ID;
                    if (tileID == 0) continue; // Ignorar tiles vacíos

                    // Calcular posición en la textura del tileset
                    tileID--; // Ajuste de índice basado en 1
                    int tu = tileID % tileset.getColumnCount();
                    int tv = tileID / tileset.getColumnCount();

                    // Crear el sprite del tile
                    sf::Sprite tileSprite;
                    tileSprite.setTexture(tilesetTexture);
                    tileSprite.setTextureRect(sf::IntRect(tu * tileSize.x, tv * tileSize.y, tileSize.x, tileSize.y));
                    tileSprite.setPosition(static_cast<float>(x * tileSize.x), static_cast<float>(y * tileSize.y));

                    tiles.push_back(tileSprite);
                }
            }
        }
    }
}

// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {
    for (const auto& tile : tiles) {
        ventana.draw(tile);
    }
}



