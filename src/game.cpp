#include "game.h"

     mapa mapaTest;

game::game(sf::RenderWindow& window) : _window(window) {

     // Espera hasta que el mapa esté completamente cargado antes de continuar
    while (!mapaTest.mapaCargado()) {
        std::cout<<"Mapa cargando..."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
    font.loadFromFile("src/arial.ttf");
    textoTest.setFont(font);
    textoTest.setPosition(0,200);
    textoTest.setColor(sf::Color::Black);
    contador=0;
    textoTest.setCharacterSize(15);

}

game::~game(){}

const bool game::isRunning() const {
    return _window.isOpen();

}

void game::updateEvent(){
    while(_window.pollEvent(evento)){
            if (evento.type == sf::Event::Closed){
                _window.close();
            }

    }
}





//Toda las verificaiones y los updates de cada objeto van acÃ¡
void game::update(){

    updateEvent();

    if(corazon.getActive()==false){
       corazon.respawn();
       corazon.setActive(true);
    }
    if(star.getActive()==false){
       star.respawn(mapaTest);
       star.setActive(true);
    }
    ejemplo.update(mapaTest);

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
    _window.setView(camara);
    if(ejemplo.isCollision(star) ) {
            contador+=20;
            star.setActive(false);
        }


    if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.setActive(false);
        }


        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));
        textoTest.setString("PUNTOS: "+std::to_string(contador));
        if(contador>=60){
            mapaTest.setTextMapa(2);
            mapaTest.setNivel(2);
            mapaTest.cargarNivel2();

        }
        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));

}
//Todas las visualizaciones
void game::render(){
        _window.clear();

        mapaTest.dibujar(_window);

        _window.draw(ejemplo);
        _window.draw(corazon);
        _window.draw(star);
        _window.draw(textoTest);

        _window.display();

}
