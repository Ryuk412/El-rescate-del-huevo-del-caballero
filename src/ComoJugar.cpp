#include "ComoJugar.h"

/// constructor que inicializa el sprite y la hitbox Volver del submenú Como Jugar
ComoJugar::ComoJugar() {

    ///Fondo de Confirmacion - Propiedades
    _comoJugarTextura.loadFromFile("menu/como_jugar.png");
    _comoJugarSprite.setTexture(_comoJugarTextura);
    _comoJugarSprite.setPosition(0, 0);

    /// Hitbox: Volver - Propiedades
    _volverHitBox.setSize(sf::Vector2f(70, 20));
    _volverHitBox.setPosition(365, 529);
    _volverHitBox.setFillColor(sf::Color::Transparent);
    _volverHitBox.setOutlineColor(sf::Color::Red);
    _volverHitBox.setOutlineThickness(2);
}

/// procesa los eventos ingresados sobre la ventana
void ComoJugar::procesarEventoEntrada(sf::Event &evento){

    /// verifica si el evento es un clic de mouse
    if (evento.type == sf::Event::MouseButtonPressed){

        /// verifica si el clic está dentro del hitbox de volver
        if (_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
            _volver = true; /// cambia la bandera de volver a true
        }
    }
}

/// devuelve el hitbox de volver
sf::RectangleShape ComoJugar::getVolverHitbox(){
    return _volverHitBox; /// retorna el hitbox que permite detectar los clics en la opcion de volver
}

/// establece el valor de la bandera de volver
void ComoJugar::setVolver(bool volver){
    _volver = volver; /// asigna el valor pasado como argumento a la bandera _volver
}

/// devuelve el estado de la bandera de volver
bool ComoJugar::getVolver(){
    return _volver; /// retorna el valor actual de la bandera _volver
}

/// dibuja el sprite y el hitbox en la ventana
void ComoJugar::dibujar(sf::RenderWindow &ventana){
    ventana.draw(_comoJugarSprite); /// dibuja el sprite en la ventana
    ventana.draw(_volverHitBox); /// dibuja el hitbox en la ventana
}

