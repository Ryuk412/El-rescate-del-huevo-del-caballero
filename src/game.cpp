#include "game.h"


game::game() : window(sf::VideoMode(800, 600), "El rescate del huevo del caballero",sf::Style::Default) {
    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
    setEnemies();
    font.loadFromFile("src/arial.ttf");
    textoTest.setFont(font);
    textoTest.setPosition(0,200);
    textoTest.setFillColor(sf::Color::White);
    textoTest.setCharacterSize(15);
    contador=0;
}

game::~game(){
    skl.clear();
}

const bool game::isRunning() const {
    return window.isOpen();

}

void game::updateEvent(){
    window.pollEvent(evento);
            if (evento.type == sf::Event::Closed){
                window.close();
        }
}


void game::setEnemies(){
    //El punto en el que inicia cada enemigo.
    //Esta funcion se ejecuta en el constructor para que se ejecute una sola vez.
    skl.resize(5);
    skl[0].setSpritePosition(50,200);
    skl[1].setSpritePosition(500,250);
    skl[2].setSpritePosition(1100,450);
    skl[3].setSpritePosition(950,250);
    skl[4].setSpritePosition(500,580);
    skl[0].setLimit(10,380);
    skl[1].setLimit(440,620);
    skl[2].setLimit(1050,1200);
    skl[3].setLimit(900,1200);
    skl[4].setLimit(450,700);

}

void game::updateEnemies(){
    //El update de cada enemigo se ejecuta en una funcion aparte para que update() quede mas limpio.
    skl[0].update();
    skl[1].update();
    skl[2].update();
    skl[3].update();
    skl[4].update();
}

void game::setLevel(){
    if(contador<=0){
            mapaTest.setTextMapa(1);
            mapaTest.setNivel(1);
            mapaTest.cargarNivel1();
            dibujarUnaVez=false;
            nivel1=true;
    }
    else if(contador==60){
            mapaTest.setTextMapa(2);
            mapaTest.setNivel(2);
            mapaTest.cargarNivel2();
            ejemplo.resetPosition();
            dibujarUnaVez=false;
            nivel2=true;
        }
}

void game::checkCollisions(){
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
    if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.setActive(false);
        }
    if(ejemplo.isCollision(star) ) {
            contador+=20;
            star.setActive(false);
        }
        if(ejemplo.isCollision(slime)){
            if(ejemplo.isAlive()==false){
                ejemplo.muerte();
            }else{ejemplo.danioRecibido(25);
                   //ejemplo.respawn();             }
        }
    }
        if( ejemplo.getHitboxE().getGlobalBounds().intersects(slime.getHitbox().getGlobalBounds()) and ejemplo.getBan()){
            if(slime.isAlive()==false){
                slime.muerte();
            }else{slime.danioRecibido(25);}


        }
        if(contador==60&&nivel2==false){
                dibujarUnaVez=true;
        }

}

//Toda las verificaiones y los updates de cada objeto van acÃ¡
void game::update(){
    updateEvent();
    if(dibujarUnaVez==true){
    setLevel();
    }
    if(corazon.getActive()==false){
       corazon.respawn(mapaTest);
       corazon.setActive(true);
    }
    if(star.getActive()==false){
       star.respawn(mapaTest);
       star.setActive(true);
    }
    ejemplo.update(mapaTest);
    slime.update();
    skl[0].update();
    skl[1].update();
    skl[2].update();
    skl[3].update();
    skl[4].update();
    checkCollisions();
        //textoTest.setString("BOTON APRETADO: "+std::to_string(evento.type));
        textoTest.setString("PUNTOS: "+std::to_string(contador));
}

//Todas las visualizaciones
void game::render(){
        window.clear();
        mapaTest.dibujar(window);
        for(int i=0;i<5;i++){
        window.draw(skl[i]);
        }
        window.draw(slime);
        window.draw(ejemplo);
        window.draw(corazon);
        window.draw(star);
        window.draw(textoTest);
        window.display();

}
