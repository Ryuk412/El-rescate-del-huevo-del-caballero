#ifndef COMOJUGAR_H
#define COMOJUGAR_H

#include <SFML/Graphics.hpp>

class ComoJugar
{
private:
    sf::Texture _comoJugarTextura;
    sf::Sprite _comoJugarSprite;
    sf::RectangleShape _volverHitBox;
    bool _volver=false;

public:
    ComoJugar();
    void procesarEventoEntrada(sf::Event &evento);

    /**
        es un metodo que retorna un objeto de tipo sf::RectangleShape(rectangulo)
        representa la hitbox para la opción de volver

        se lo usara en el submenu Jugar donde si el clic del mouse esta sobre volver
        en este submenu vuelve a _enComoJugar=false y lo volveria a Opciones
    */
    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();
    void dibujar(sf::RenderWindow &ventana);
};
#endif // COMOJUGAR_H
