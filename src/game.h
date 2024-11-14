#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "enemigo.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "Jefe.h"
#include "clsPJ.h"
#include "Item.h"
#include "mapa.h"
#include "enemigoEsqueleto.h"
#include "enemigoSlime.h"
#include "itemPuntos.h"

//Clase que funciona como el game engine.

class game{
    private:
    //Variables que solo la clase game puede tener acceso:

        sf::Event evento;
        sf::View camara;

        pj ejemplo;
        Jefe oso;
        Item corazon;
        int contador;
        itemPuntos star;
        sf::Font font;
        sf::Text textoTest;
        float limiteCamaraIzq=400;
        //caso de mapa jefe:
        float limiteCamaraDer=1200;
        //caso de mapa comun: float limiteCamaraDer=1200;

        sf::Sprite _nv;
        sf::Texture _textura;
        void setLevel();
        bool nivel2=false;
    public:
    //Constructor y destructor
        game(sf::RenderWindow& window);
        virtual ~game();
    //Nexo entre game y main:
        const bool isRunning(sf::RenderWindow& window) const;
    //Funciones:
        void updateEvent(sf::RenderWindow& window);
        void update(sf::RenderWindow& window);
        void render(sf::RenderWindow& window);

};

#endif // GAME_H_INCLUDED
