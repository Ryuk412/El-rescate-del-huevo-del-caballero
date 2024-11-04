#ifndef CARGARPARTIDA_H
#define CARGARPARTIDA_H

#include <SFML/Graphics.hpp>


class CargarPartida{
private:
    sf::Texture _cargarPartidaTextura; ///donde se cargara la textura
    sf::Sprite _cargarPartidaSprite; ///el sprite del submenu
    sf::RectangleShape _volverHitBox; ///hitbox para volver al submenu Jugar

    bool _volver=false;

public:
    CargarPartida();
    void procesarEventoEntrada(sf::Event &evento);
    void dibujar(sf::RenderWindow &ventana);

    /**
        es un metodo que retorna un objeto de tipo sf::RectangleShape(rectangulo)
        representa la hitbox para la opción de volver

        se lo usara en el submenu Jugar donde si el clic del mouse esta sobre volver
        en este submenu vuelve a _enCargarPartida=false
    */
    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

};

#endif // CARGARPARTIDA_H
