#include "game.h"

     mapa mapaTest;

game::game(sf::RenderWindow& window)
    : pausa(690, 55, 50, 50, " ")
{
    while (!mapaTest.mapaCargado()) {
        std::cout<<"Mapa cargando..."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    window.setFramerateLimit(60);
    camara.setSize(800.0f,600.0f);
    camara.move(0,-200);
    font.loadFromFile("menu/fuente/PixelifySans-Bold.ttf");
    contador=0;
    textoTest.setCharacterSize(15);
    textoTest.setFont(font);
    textoTest.setPosition(30,25);
    textoTest.setFillColor(sf::Color::White);
    caballeroVida.setCharacterSize(15);
    caballeroVida.setFont(font);
    caballeroVida.setPosition(30,55);
    caballeroVida.setFillColor(sf::Color::White);
    nivelActual=1;
    respawnMap(nivelActual);

    enPausa=0;
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

void game::respawnMap(int nivelActual){
    //Esta función se llama cada vez que el personaje muere
    ejemplo.setLife();
    enemigos.clear();
    //Pushback agranda el vector dinamicamente, con cada uso se le agrega un elemento más al final del vector.
    //unique_ptr es un puntero que maneja la devolución de memoria más eficientemente y con más seguridad.
    //La clase abstracta enemigoBase engloba todas las clases heredadas de enemigos, esto permite que el vector enemigoBase contenga cualquier clase que la hereda.
    //Primero se le dice a unique_ptr que tipo de puntero va a generar, despues se llama a un new clase de enemigo.
    switch(nivelActual){
        case 1:
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[0]->setSpritePosition(110, 200, 100, 300);
            /*enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[1]->setSpritePosition(800, 360, 750, 1000);

            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[2]->setSpritePosition(520, 575, 490, 680);

            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[3]->setSpritePosition(1000, 250, 950, 1200);

            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[4]->setSpritePosition(1100, 450, 1050, 1350);*/
            break;
        case 2:
            enemigos.clear();
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[0]->setSpritePosition(300,140,230,380);
            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[1]->setSpritePosition(900,500,800,1000);
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[2]->setSpritePosition(300,450,230,450);
            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[3]->setSpritePosition(200,470,100,250);
            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[4]->setSpritePosition(1400,520,1300,1500);
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[5]->setSpritePosition(1400,520,1200,1550);
            break;
        default:
            break;

    }
}

void game::setLevel(int nivelActual){
    switch(nivelActual){
        case 1:
            //Esta función haría lo mismo que arriba, con la diferencia que esta vez necesita setear la textura de mapa y los hitboxes correctos.
            mapaTest.setTextMapa(2);
            mapaTest.setNivel(2);
            mapaTest.cargarNivel2();
            ejemplo.setLife();
            enemigos.clear();
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[0]->setSpritePosition(300,140,230,380);
            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[1]->setSpritePosition(900,500,800,1000);
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[2]->setSpritePosition(300,450,230,450);
            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[3]->setSpritePosition(200,470,100,250);
            enemigos.push_back(std::unique_ptr<enemigo2>(new enemigo2()));
            this->enemigos[4]->setSpritePosition(1400,520,1300,1500);
            enemigos.push_back(std::unique_ptr<enemigo>(new enemigo()));
            this->enemigos[5]->setSpritePosition(1400,520,1200,1550);
            break;
        case 2:
            mapaTest.setTextMapa(3);
            mapaTest.setNivel(3);
            mapaTest.cargarNivel3();
            ejemplo.setLife();
            enemigos.clear();
            break;
    }
}

void game::updateCharacters(){
    ejemplo.update(mapaTest);
    //For dinámico con el update de cada enemigo en pantalla
    for(int i=0;i<enemigos.size();i++){
        this->enemigos[i]->update(ejemplo);
    }

    oso.update(mapaTest,ejemplo);
    caballeroVida.setPosition(ejemplo.getPositionX()+10,ejemplo.getPositionY()+20);
    textoTest.setPosition(ejemplo.getPositionX()+10,ejemplo.getPositionY()+10);
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

    if(ejemplo.isCollision(corazon)){
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
        contador=contador-100;
        respawnMap(nivelActual);
    }
    if(enemigos.size()==0){
            setLevel(nivelActual);
            nivelActual=2;
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            enPausa=1;
}

}

//Todas las visualizaciones
void game::render(sf::RenderWindow& window){
        window.clear();
        mapaTest.dibujar(window);

        if(enPausa){
            pausaMenu(window);
            enPausa=0;
        }

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
