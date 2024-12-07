#include "CargarPartida.h"
#include "ArchivoJugadores.h"

void cargarPartidaMenu(sf::RenderWindow& window){

    Boton volver(363, 463, 70, 20, " ");

    sf::Texture _textura;
    if(!_textura.loadFromFile("menu/cargar_partida.png")){return;}


    ArchivoJugadores archivo;
    std::string cantRegistros=archivo.listarRegistro();

    sf::Font fuente;
    if(!fuente.loadFromFile("menu/fuente/Arimo-Bold.ttf")){return;}
    sf::Text texto;
    texto.setFont(fuente);
    texto.setCharacterSize(24);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(160, 230);
    texto.setString(cantRegistros);


    while(window.isOpen()){
        sf::Event evento;

        while(window.pollEvent(evento)){

            if(evento.type == sf::Event::Closed){
                window.close();
            }

            if(evento.type == sf::Event::MouseButtonPressed){

                if(volver.MouseClick(window)){
                    return;
                }
            }
        }

        window.clear();

        sf::Sprite sprite(_textura);
        window.draw(sprite);

        window.draw(texto);
        volver.draw(window);

        window.display();
    }
}
