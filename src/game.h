#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "enemigo.h"
#include "Jefe.h"
#include "pj.h"
#include "Item.h"
#include "mapa.h"
#include "enemigoEsqueleto.h"
#include "enemigoSlime.h"
//Clase que funciona como el game engine.

class game{
    private:
    //Variables que solo la clase game puede tener acceso:
        mapa mapaTest;
        sf::RenderWindow window{};
        sf::Event evento;
        sf::View camara;
        enemigo slime;
        std::vector<enemigoSlime> skl;
        Jefe mago;
        pj ejemplo;
        Item corazon;
        sf::Font font;
        sf::Text textoTest;
        float limiteCamaraIzq=400;
        float limiteCamaraDer=1200;
    public:
    //Constructor y destructor
        game();
        virtual ~game();
    //Nexo entre game y main:
        const bool isRunning() const;
    //Funciones:
        bool verificarColisionEnemigo(sf::RectangleShape hitbox);
        void updateEvent();
        void update();
        void render();
        void setEnemies();
        void updateEnemies();
};

#endif // GAME_H_INCLUDED
