#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "data/characters/pj.h"
using namespace std;
using namespace sf;


int main()
{
    pj asd;
    RenderWindow window(sf::VideoMode(800, 600), "El rescate del huevo del caballero");
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(asd);
        window.display();
    }

    return 0;
}
