#include "game.h"


game::game() : mapaTest("data/maps/nivel2_mapa.png"), window(sf::VideoMode(800, 600), "El rescate del huevo del caballero",sf::Style::Default) {

    skl.resize(5);
    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
    setEnemies();
    font.loadFromFile("src/arial.ttf");
    textoTest.setFont(font);
    textoTest.setPosition(0,200);
    textoTest.setColor(sf::Color::Cyan);
    textoTest.setCharacterSize(15);
    contador=0;
}

game::~game(){}

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

void game::setEnemies(){
    //El punto en el que inicia cada enemigo.
    //Esta funcion se ejecuta en el constructor para que se ejecute una sola vez.
    skl[0].setSpritePosition(10,200);
    skl[1].setSpritePosition(440,250);
    skl[2].setSpritePosition(1050,450);
    skl[3].setSpritePosition(900,250);
    skl[4].setSpritePosition(450,580);

}

void game::updateEnemies(){
    //El update de cada enemigo se ejecuta en una funcion aparte para que update() quede mas limpio.
    skl[0].update(10,380);
    skl[1].update(440,620);
    skl[2].update(1050,1200);
    skl[3].update(900,1200);
    skl[4].update(450,700);
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
    updateEnemies();
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
