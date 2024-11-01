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

    // Metodo para crear una hitbox
    bool cargarHitbox(int vecPos,float w,float h,float x, float y);
    // Metodo para dibujar hitbox
    void dibujarHitbox(sf::RenderWindow& ventana);
    // Metodo para verificar la colision
    bool verificarColision(const sf::RectangleShape& objeto);


private:
    sf::Texture _mapa;        // Textura del mapa
    sf::Sprite _Smapa;        // Sprite del mapa
    std::vector<sf::RectangleShape> _hitbox;  // Terreno
    bool _dibujado=false;     // Booleano para solo dibujar una vez todas las hitbox



    void cargarMapa(); // Método para cargar el mapa
};

#endif // MAPA_H
