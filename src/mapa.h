#ifndef MAPA_H
#define MAPA_H
#include "inc.h"

class mapa{

public:
    mapa();
    ~mapa();
    void cargarMapaEnHilo();
    bool mapaCargado() const{return _cargado;}
    bool cargarEstructura();
    void dibujar(sf::RenderWindow& ventana);
    void cargarTexturaMapa();
    bool cargarHitbox(int vecPos, float w, float h, float x, float y);
    void dibujarHitbox(sf::RenderWindow& ventana);
    bool verificarColision(const sf::RectangleShape& objeto);
    void setNivel(int nivel);
    void setTextMapa(int nivel);
    bool cargarNivel1();
    bool cargarNivel2();
    bool cargarNivel3();
    void inicializarVector(int tam);
    int getNivel();

private:
    sf::Texture _mapa;
    sf::Sprite _Smapa;
    sf::Texture _nivel1;
    sf::Texture _nivel2;
    sf::Texture _nivel3;

    std::atomic<bool> _cargado{false};

    int _nivel = 1;
    std::vector<sf::RectangleShape> _hitbox;
    bool _dibujado = false;
    void cargarMapa();
};

#endif // MAPA_H
