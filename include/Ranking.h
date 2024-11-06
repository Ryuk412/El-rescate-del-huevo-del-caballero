#ifndef RANKING_H
#define RANKING_H

#include <SFML/Graphics.hpp>

class Ranking
{
private:
    sf::Texture _rankingTextura;
    sf::Sprite _rankingSprite;

    sf::RectangleShape _volverHitBox;

    bool _volver=false;


public:
    Ranking();
    void procesarEventoEntrada(sf::Event &evento);

    sf::RectangleShape getVolverHitbox();
    void setVolver(bool volver);
    bool getVolver();

    void dibujar(sf::RenderWindow &ventana);
};

#endif // RANKING_H
