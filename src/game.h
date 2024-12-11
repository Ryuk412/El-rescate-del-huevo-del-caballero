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
#include <memory>
#include <vector>
#include "Jefe.h"
#include "clsPJ.h"
#include "Item.h"
#include "mapa.h"
#include "enemigo2.h"
#include "itemPuntos.h"
#include "Botones.h"
#include "Pausa.h"
#include "GameOver.h"
#include "Jugador.h"
#include "Final.h"

//Clase que funciona como el game engine.

class game{
    private:
    //Variables que solo la clase game puede tener acceso:
        sf::Event evento;
        sf::View camara;
        pj ejemplo;
        std::vector<std::unique_ptr<enemigoBase>> enemigos;
        Item corazon;
        itemPuntos star;

        int contador;

        sf::Font font;
        sf::Text textoPuntos;
        sf::Text caballeroVida;

        float limiteCamaraIzq=400;
        float limiteCamaraDer=1200;

        sf::Sprite _nv;
        sf::Texture _textura;
        mapa mapaTest;
    //Funciones privadas de la funcion publica update:
        void setLevel(int nivelActual);
        void updateCharacters();
        void updateCamera(sf::RenderWindow& window);
        void checkCollisions(sf::RenderWindow& window);
        void respawnMap(int nivelActual);
        int nivelActual;
        bool lvl1=true;
        bool lvl2=false;
        bool lvl3=false;

        bool enGameOver;
        bool enPausa;

        Final finalm;
        Jugador jugador;
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
