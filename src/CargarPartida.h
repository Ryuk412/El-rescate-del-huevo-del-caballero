#ifndef CARGARPARTIDA_H
#define CARGARPARTIDA_H

#include <SFML/Graphics.hpp>

/**

    - cargar partida: las partidas guardadas

    - los puntajes (ranking) opciones
    - selecciona un espacio

        hay un espacio de 3 ranuras como max
        una vez llenadas o completadas cuando un nuevo usuario termine su nv/partida, y las ranuras esten llenas
        el mismo podra elegir el espacio o ranura que desee ocupar, eliminando el archivo/historial del otro jugador

        preguntar por su confirmacion -> confirmacion.h

*/

class CargarPartida {
private:
    sf::Texture _cargarPartidaTextura; ///donde se cargara la textura
    sf::Sprite _cargarPartidaSprite; ///el sprite del submenu
    sf::RectangleShape _volverHitBox; ///hitbox para volver al submenu Jugar
    sf::Font _fuente;/// guarda la fuente para el txt de cada hitbox
    /// [completar] para mostrar los nombres de los jugadores con sus puntajes
    sf::Text _textoJugadores[3];
    int _cantidadJugadores;
    bool _volver;///bandera que dice si tiene que volver al menu anterior

public:
    CargarPartida();
    void procesarEventoEntrada(sf::Event &evento);
    void cargarJugadores();
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
