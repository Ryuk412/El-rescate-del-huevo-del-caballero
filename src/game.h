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
#include "pj.h"
#include "Item.h"
#include "mapa.h"
#include "enemigoEsqueleto.h"
#include "itemPuntos.h"
//Clase que funciona como el game engine.

class game{
    private:
    //Variables que solo la clase game puede tener acceso:
        mapa mapaTest;
        sf::RenderWindow window{};
        sf::Event evento;
        sf::View camara;
        enemigo slime;
        std::vector<enemigoEsqueleto> skl;
        pj ejemplo;
        Item corazon;
        itemPuntos star;
        int contador;
        sf::Font font;
        sf::Text textoTest;
        float limiteCamaraIzq=400;
        float limiteCamaraDer=1200;
        void checkCollisions();
        void setLevel();
    public:
    //Constructor y destructor
        game();
        virtual ~game();
    //Nexo entre game y main:
        const bool isRunning() const;
    //Funciones:
        void updateEvent();
        void update();
        void render();
        void setEnemies();
        void updateEnemies();
        bool dibujarUnaVez=true;
        bool nivel1=false;
        bool nivel2=false;
};

#endif // GAME_H_INCLUDED
