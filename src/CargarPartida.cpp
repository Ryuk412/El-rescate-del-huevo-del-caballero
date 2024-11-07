#include "CargarPartida.h"

/// constructor que inicializa el sprite y la hitbox Volver del submenú CargarPartida
CargarPartida::CargarPartida(){

    ///Fondo de CargarPartida - Propiedades
    _cargarPartidaTextura.loadFromFile("menu/cargar_partida.png");///fondo
    _cargarPartidaSprite.setTexture(_cargarPartidaTextura);///sprite
    _cargarPartidaSprite.setPosition(0, 0);///su posicion en la venta

    ///Hitbox Volver - Propiedades
    _volverHitBox.setSize(sf::Vector2f(70, 18)); ///tamaño
    _volverHitBox.setPosition(365, 465); ///posicion
    _volverHitBox.setFillColor(sf::Color::Transparent);///color de fondo

    _fuente.loadFromFile("menu/fuente/Arimo-Bold.ttf");
    _registroTexto.setFont(_fuente);
    _registroTexto.setPosition(170,237);
    _registroTexto.setFillColor(sf::Color::White);
    _registroTexto.setCharacterSize(30);
}

///procesa los eventos ingresados sobre la ventana
void CargarPartida::procesarEventoEntrada(sf::Event &evento){

    /// verifica si el evento es un clic de mouse
    if (evento.type == sf::Event::MouseButtonPressed){
        /// verifica si el clic está dentro del hitbox de volver
        if (_volverHitBox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)){
            _volver = true; /// cambia la bandera de volver a true
        }
    }
}

/// devuelve el hitbox de volver
sf::RectangleShape CargarPartida::getVolverHitbox(){
    return _volverHitBox;
}

/// establece el valor de la bandera de volver
void CargarPartida::setVolver(bool volver){
    _volver = volver;
}

/// devuelve el estado de la bandera de volver
bool CargarPartida::getVolver(){
    return _volver;
}

///dibuja fondo, jugadores y hitbox en la ventana
void CargarPartida::dibujar(sf::RenderWindow &ventana){

    ventana.clear(); ///limpia la ventana
    ventana.draw(_cargarPartidaSprite); ///dibuja el fondo

    ventana.draw(_volverHitBox);


    ///obtiene la lista de registros y la configura en el texto
    std::string registros= _archivo.listarRegistro();  ///obtiene los nombres de los jugadores
    _registroTexto.setString(registros); ///hace un string con los registros

    ///dibuja el texto con los registros en la ventana
    ventana.draw(_registroTexto);

}
