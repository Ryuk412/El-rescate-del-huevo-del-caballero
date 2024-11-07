#include "game.h"


game::game() : window(sf::VideoMode(800, 600), "El rescate del huevo del caballero",sf::Style::Default) {
    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
    font.loadFromFile("src/arial.ttf");
    textoTest.setFont(font);
    textoTest.setPosition(0,200);
    textoTest.setFillColor(sf::Color::White);
    textoTest.setCharacterSize(15);
    contador=0;
    setLevel();
}

game::~game(){
}

const bool game::isRunning() const {
    return window.isOpen();

}

void game::updateEvent(){
    while (window.pollEvent(evento)){
            if (evento.type == sf::Event::Closed){
                window.close();
        }
}
}



void game::setLevel(){
    /*if(contador<=0){
            mapaTest.setTextMapa(1);
            mapaTest.cargarEstructura();
            enemyManager.setEnemies();
            nivel1=true;
    }
    else if(contador==60){
            mapaTest.setTextMapa(2);
            mapaTest.cargarNivel2();
        }*/
        mapaTest.setTextMapa(3);
        mapaTest.cargarEstructura();
        enemyManager.setEnemies();
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
    enemyManager.updateEnemies(ejemplo);
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


    if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.setActive(false);
        }
        if(enemyManager.verificarColisionEnemigo(ejemplo.getHitbox())){

                if(ejemplo.isAlive()==false){
                    ejemplo.muerte();


                }
                ejemplo.danioRecibido(25);
        }
                   //ejemplo.respawn();
        if(enemyManager.verificarColisionEspada(ejemplo ,ejemplo.getHitboxE())){
        std::cout << "Colision detectada." << std::endl;

        }

        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));
        textoTest.setString("PUNTOS: "+std::to_string(contador));
        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));
        /*if(contador==60&&nivel2==false){
            setLevel();
            nivel2=true;
        }*/

}
//Todas las visualizaciones
void game::render(){
        window.clear();
        mapaTest.dibujar(window);
        enemyManager.draw(window, Default);
        window.draw(ejemplo);
        window.draw(corazon);
        window.draw(star);
        window.draw(textoTest);
        window.display();

}
