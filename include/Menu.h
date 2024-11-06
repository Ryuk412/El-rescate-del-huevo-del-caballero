#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Musica.h"
#include "Jugar.h"
#include "Creditos.h"
#include "Opciones.h"

class Menu
{
public:
    Menu();
    void procesarEventoEntrada(sf::Event &evento);
    void dibujar(sf::RenderWindow &ventana);

private:
    sf::Texture _fondoTextura;
    sf::Sprite _fondo;
    Jugar _jugar;

    Creditos _creditos;
    Opciones _opciones;
    Musica _musica;

    bool _enJugar=false;
    bool _enCreditos=false;
    bool _enOpciones=false;

    sf::Font _fuente;

    sf::Text _jugarTexto, _opcionesTexto, _creditosTexto, _salirTexto;
    sf::RectangleShape _jugarHitbox, _opcionesHitbox, _creditosHitbox, _salirHitbox, _volverHitbox;
};

#endif // MENU_H
