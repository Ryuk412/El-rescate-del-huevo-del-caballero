#include "Jugador.h"

void Jugador::setNombreJugador(std::string nombre){
    _nombreJugador=nombre;
}
std::string Jugador::getNombreJugador(){
    return _nombreJugador;
}
