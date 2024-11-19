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
    nivel1();
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
    slime.setSpritePosition(420,200,380,600);
    esqueleto.setSpritePosition(900,450,850,1200);
}


void game::nivel1(){
    slime.setSpritePosition(100,200,120,300);
    esqueleto.setSpritePosition(800,360,750,1000);
}

void game::updateCharacters(){
    ejemplo.update(mapaTest);
    oso.update(mapaTest,ejemplo);
    slime.update(ejemplo);
    esqueleto.update(ejemplo);
}

void game::checkCollisions(){
    if(corazon.getActive()==false){
       corazon.respawn(mapaTest);
       corazon.setActive(true);
    }
    if(star.getActive()==false){
       star.respawn(mapaTest);
       star.setActive(true);
    }

    if(ejemplo.isCollision(star) ) {
            contador+=20;
            star.setActive(false);
    }

    if(ejemplo.isCollision(corazon) ) {
        ejemplo.curar(25);
        corazon.setActive(false);
    }

    if(ejemplo.getHitbox().getGlobalBounds().intersects(slime.getDamageHitbox().getGlobalBounds())){
        ejemplo.danioRecibido(25);
    }

    if(ejemplo.getHitbox().getGlobalBounds().intersects(esqueleto.getDamageHitbox().getGlobalBounds())){
        ejemplo.danioRecibido(40);
    }
    if(!ejemplo.isAlive()){
        ejemplo.respawn();
        slime.respawn();
        esqueleto.respawn();
    }
    if(contador==200&&nivel2==false){
            setLevel();
            nivel2=true;
        }
}

void game::updateCamera(sf::RenderWindow& window){
    // Verificar si el personaje ha pasado el l�mite para mover la c�mara
        if (ejemplo.getPositionX() > limiteCamaraIzq) {
            // Centrar la vista en el personaje solo en el eje horizontal
            camara.setCenter(ejemplo.getPositionX(), camara.getCenter().y);
        } else {
            // Si el personaje est� antes del l�mite, la c�mara se queda al inicio
            camara.setCenter(limiteCamaraIzq, camara.getCenter().y);
        }
        if (ejemplo.getPositionX() > limiteCamaraDer && ejemplo.getPositionX() > limiteCamaraIzq) {
            // Si el personaje est� antes del l�mite, la c�mara se queda al inicio
            camara.setCenter(limiteCamaraDer, camara.getCenter().y);
        }


    // Actualizar la vista en la ventana
    window.setView(camara);
}

//Toda las verificaiones y los updates de cada objeto van acá
void game::update(sf::RenderWindow& window){
    updateEvent(window);
    updateCharacters();
    updateCamera(window);
    checkCollisions();
    textoTest.setString("PUNTOS: "+std::to_string(contador));
}
//Todas las visualizaciones
void game::render(sf::RenderWindow& window){
        window.clear();

        mapaTest.dibujar(window);

        window.draw(ejemplo);
        window.draw(oso);
        window.draw(corazon);
        window.draw(slime);
        window.draw(esqueleto);
        window.draw(star);
        window.draw(textoTest);

        window.display();

}
