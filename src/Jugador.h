#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
class Jugador{
private:
    std::string _nombreJugador;


public:
    void setNombreJugador(std::string nombre);
    std::string getNombreJugador();
};

#endif // JUGADOR_H
