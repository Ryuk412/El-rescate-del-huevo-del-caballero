#include "Botones.h"
#include <iostream>
using namespace std;

Boton::Boton(float x, float y, float ancho, float alto, const std::string& texto){

    formaboton.setPosition(x, y);
    formaboton.setSize(sf::Vector2f(ancho, alto));
    formaboton.setFillColor(sf::Color::Transparent);

    if(!fuente.loadFromFile("menu/fuente/PixelifySans-Bold.ttf")){cout<<"No se pudo usar la fuente"<<endl;}
    botontexto.setFont(fuente);
    botontexto.setString(texto);
    botontexto.setCharacterSize(30);
    botontexto.setFillColor(sf::Color::White);

    botontexto.setPosition(x + (ancho - botontexto.getLocalBounds().width) / 2, y + (alto - botontexto.getLocalBounds().height) / 4);
}

void Boton::draw(sf::RenderWindow& window){
    window.draw(formaboton);
    window.draw(botontexto);
}

bool Boton::MouseClick(sf::RenderWindow& window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return formaboton.getGlobalBounds().contains(mousePos.x, mousePos.y);
}
