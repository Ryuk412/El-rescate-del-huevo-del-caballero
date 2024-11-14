#include "game.h"

     mapa mapaTest;

game::game(sf::RenderWindow& window){

    while (!mapaTest.mapaCargado()) {
        std::cout<<"Mapa cargando..."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
    font.loadFromFile("menu/fuente/PixelifySans-Bold.ttf");
    textoTest.setFont(font);
    textoTest.setPosition(30,25);
    textoTest.setFillColor(sf::Color::White);
    contador=0;
    textoTest.setCharacterSize(30);

}

game::~game(){}

const bool game::isRunning(sf::RenderWindow& window) const {
    return window.isOpen();

}

void game::updateEvent(sf::RenderWindow& window){
    while(window.pollEvent(evento)){
            if (evento.type == sf::Event::Closed){
                window.close();
            }

    }
}

void game::setLevel(){
            mapaTest.setTextMapa(2);
            mapaTest.setNivel(2);
            mapaTest.cargarNivel2();
            ejemplo.setPosicion();

}
//Toda las verificaiones y los updates de cada objeto van acÃ¡
void game::update(sf::RenderWindow& window){

    updateEvent(window);

    if(corazon.getActive()==false){
       corazon.respawn(mapaTest);
       corazon.setActive(true);
    }
    if(star.getActive()==false){
       star.respawn(mapaTest);
       star.setActive(true);
    }
    ejemplo.update(mapaTest);
    oso.update(mapaTest,ejemplo);
    // Verificar si el personaje ha pasado el límite para mover la cámara
        if (ejemplo.getPositionX() > limiteCamaraIzq) {
            // Centrar la vista en el personaje solo en el eje horizontal
            camara.setCenter(ejemplo.getPositionX(), camara.getCenter().y);
        } else {
            // Si el personaje está antes del límite, la cámara se queda al inicio
            camara.setCenter(limiteCamaraIzq, camara.getCenter().y);
        }
        if (ejemplo.getPositionX() > limiteCamaraDer && ejemplo.getPositionX() > limiteCamaraIzq) {
            // Si el personaje está antes del límite, la cámara se queda al inicio
            camara.setCenter(limiteCamaraDer, camara.getCenter().y);
        }


    // Actualizar la vista en la ventana
    window.setView(camara);
    if(ejemplo.isCollision(star) ) {
            contador+=20;
            star.setActive(false);
        }

if(ejemplo.isCollision(oso)){
    if(ejemplo.isAlive()==false){
        ejemplo.muerte();
    }
    oso.ataque();
    ejemplo.danioRecibido(25);

}

    if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.setActive(false);
        }


        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));
        textoTest.setString("PUNTOS: "+std::to_string(contador));
        if(contador==60&&nivel2==false){
            setLevel();
            nivel2=true;
        }
        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));

}
//Todas las visualizaciones
void game::render(sf::RenderWindow& window){
        window.clear();

        mapaTest.dibujar(window);

        window.draw(ejemplo);
        window.draw(oso);
        window.draw(corazon);
        window.draw(star);
        window.draw(textoTest);

        window.display();

}
