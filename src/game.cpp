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
    respawnMap1();
    nivelActual=1;
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

void game::gameLoop(sf::RenderWindow& window){//Por ahora en desuso
    while(true){
        switch(nivelActual){
            case 1:
                nivel1(window);
            case 2:
                nivel2(window);
        }
    }
}

void game::respawnMap1(){
    //Esta función se llama cada vez que el personaje muere
    ejemplo.setLife();
    enemigos.clear();
    //Pushback agranda el vector dinamicamente, con cada uso se le agrega un elemento más al final del vector.
    //unique_ptr es un puntero que maneja la devolución de memoria más eficientemente y con más seguridad.
    //La clase abstracta enemigoBase engloba todas las clases heredadas de enemigos, esto permite que el vector enemigoBase contenga cualquier clase que la hereda.
    //Primero se le dice a unique_ptr que tipo de puntero va a generar, despues se llama a un new clase de enemigo.
    enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
    this->enemigos[0]->setSpritePosition(110, 200, 100, 300);

    enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
    this->enemigos[1]->setSpritePosition(800, 360, 750, 1000);

    enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
    this->enemigos[2]->setSpritePosition(520, 575, 490, 680);
}

void game::setLevel2(){
    //Esta función haría lo mismo que arriba, con la diferencia que esta vez necesita setear la textura de mapa y los hitboxes correctos.
    mapaTest.setTextMapa(2);
    mapaTest.setNivel(2);
    mapaTest.cargarNivel2();
    ejemplo.setLife();
    enemigos.clear();
    enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
    this->enemigos[0]->setSpritePosition(420,200,380,600);
    enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
    this->enemigos[1]->setSpritePosition(900,450,850,1200);
}

void game::nivel1(sf::RenderWindow& window){//Por ahora en desuso
    respawnMap1();
    while(lvl1){
        update(window);
    }
    nivelActual=2;
    return;
}



void game::nivel2(sf::RenderWindow& window){//Por ahora en desuso
    setLevel2();
    while(lvl2){
        update(window);
    }
    return;
}


void game::updateCharacters(){
    ejemplo.update(mapaTest);
    //For dinámico con el update de cada enemigo en pantalla
    for(int i=0;i<enemigos.size();i++){
        this->enemigos[i]->update(ejemplo);
    }

    oso.update(mapaTest,ejemplo);
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
    //For dinámico donde se verifica si la hitbox de pj se cruza con algún ataque de los enemigos en el vector
    for(int i=0;i<enemigos.size();i++){
    if(ejemplo.getHitbox().getGlobalBounds().intersects(this->enemigos[i]->getDamageHitbox().getGlobalBounds())){
        ejemplo.danioRecibido(this->enemigos[i]->getDamage());
        }
    }
    //Se verifica si la hitbox de la espada se cruza con alguna hitbox del enemigo.
    //Se necesita un bool para que esto pase una sola vez mientras que la hitbox de la espada está en pantalla.
    //Sin un bool el enemigo recibe daño por cada frame donde la espada y la hitbox interactuen, setDamageFlag se asegura de que solo tome daño una vez.
    for(int i=0;i<enemigos.size();i++){
        if(ejemplo.getHitboxE().getGlobalBounds().intersects(this->enemigos[i]->getHitbox().getGlobalBounds())&&ejemplo.getBan()==true&&ejemplo.getDamageFlag()==false){
            this->enemigos[i]->danioRecibido(25);
            ejemplo.setDamageFlag(true);
        }
   }

   for (int i = enemigos.size() - 1; i >= 0; i--) {
    //Acá i se decrementa porque empezamos desde el último enemigo en el vector.
    if (!this->enemigos[i]->isAlive()) {
        enemigos.erase(enemigos.begin() + i);
    }
}
    if(!ejemplo.isAlive()||ejemplo.getHitbox().getGlobalBounds().top + ejemplo.getHitbox().getGlobalBounds().height > 600){
        respawnMap1();
    }
    if(contador==200&&lvl2==false){
            setLevel2();
            lvl2=true;
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
