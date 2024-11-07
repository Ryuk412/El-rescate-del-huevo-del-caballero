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
#include "enemigoSlime.h"
#include "itemPuntos.h"

//Clase que funciona como el game engine.

class game{
    private:
    //Variables que solo la clase game puede tener acceso:
        mapa mapaTest;
        sf::RenderWindow window;
        sf::Event evento;
        sf::View camara;
        std::vector<enemigoSlime> skl;
        pj ejemplo;
        Item corazon;
        int contador;
        itemPuntos star;
        sf::Font font;
        sf::Text textoTest;
        float limiteCamaraIzq=400;
        float limiteCamaraDer=1200;

        sf::Sprite _nv;
        sf::Texture _textura;

    public:
    //Constructor y destructor
        game();
        virtual ~game();
    //Nexo entre game y main:
        const bool isRunning() const;
    //Funciones:
        bool verificarColisionEnemigo(sf::RectangleShape hitbox);
        bool verificarColisionEspada(pj& p,sf::RectangleShape hitbox);
        void updateEvent();
        void update();
        void render();
        void setEnemies();
        void updateEnemies();
};

#endif // GAME_H_INCLUDED
