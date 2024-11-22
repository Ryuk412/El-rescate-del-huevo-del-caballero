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
    caballeroVida.setFont(font);
    caballeroVida.setPosition(30,40);
    caballeroVida.setFillColor(sf::Color::White);
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
    this->enemigos[0]->setSpritePosition(420,200,380,600);
    this->enemigos[1]->setSpritePosition(900,450,850,1200);
}


void game::nivel1(){
    ejemplo.setLife();
    enemigos.push_back(new enemigo());
    this->enemigos[0]->setSpritePosition(110,200,100,300);
    enemigos.push_back(new enemigo2());
    this->enemigos[1]->setSpritePosition(800,360,750,1000);
    enemigos.push_back(new enemigo());
    this->enemigos[2]->setSpritePosition(520,575,490,680);
}

void game::updateCharacters(){
    ejemplo.update(mapaTest);

    for(int i=0;i<enemigos.size();i++){
        this->enemigos[i]->update(ejemplo);
    }

    oso.update(mapaTest,ejemplo);
}
void game::respawnMap(){
    ejemplo.setLife();
    enemigos.clear();
    nivel1();
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

    if(ejemplo.isCollision(star)) {
            contador+=20;
            star.setActive(false);
    }

    if(ejemplo.isCollision(corazon) ) {
        ejemplo.curar(25);
        corazon.setActive(false);
    }

    for(int i=0;i<enemigos.size();i++){
    if(ejemplo.getHitbox().getGlobalBounds().intersects(this->enemigos[i]->getDamageHitbox().getGlobalBounds())){
        ejemplo.danioRecibido(this->enemigos[i]->getDamage());
        }
    }

    if(!ejemplo.isAlive()){
        respawnMap();
    }

    for(int i=0;i<enemigos.size();i++){
        if(ejemplo.getHitboxE().getGlobalBounds().intersects(this->enemigos[i]->getHitbox().getGlobalBounds())&&ejemplo.getBan()==true&&ejemplo.getDamageFlag()==false){
            this->enemigos[i]->danioRecibido(25);
            ejemplo.setDamageFlag(true);
        }
   }
   for(int i=0;i<enemigos.size();i++){
        if(!this->enemigos[i]->isAlive()){
            enemigos.erase(enemigos.begin()+i);
            i--;
            //Aca hay que decrementar una iteración porque tras borrar un enemigo, todos los que estaban adelante se mueven para la izquierda.
        }
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
    //textoTest.setString("PUNTOS: "+std::to_string(contador));
    textoTest.setString("VIDA DEL ENEMIGO: "+std::to_string((int)enemigos[0]->getVida()));
    caballeroVida.setString("VIDA DEL CABALLERO: "+std::to_string((int)ejemplo.getVida()));
}
//Todas las visualizaciones
void game::render(sf::RenderWindow& window){
        window.clear();
        mapaTest.dibujar(window);

        window.draw(ejemplo);
        window.draw(oso);
        window.draw(corazon);
        for(int i=0;i<enemigos.size();i++){
            window.draw(*enemigos[i]);
        }
        window.draw(star);
        window.draw(textoTest);
        window.draw(caballeroVida);
        window.display();
}
