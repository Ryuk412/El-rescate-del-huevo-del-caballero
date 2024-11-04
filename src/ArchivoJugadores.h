#ifndef ARCHIVOJUGADORES_H_INCLUDED
#define ARCHIVOJUGADORES_H_INCLUDED

#include "Jugador.h"
#include <iostream>
using namespace std;

class ArchivoJugadores {
private:
    string nombre;

public:
    ArchivoJugadores(const string &n = "jugadores.dat"); // Constructor
    Jugador leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(const Jugador &jugador);
    void listarRegistro();
    void vaciar();
};

#endif // ARCHIVOJUGADORES_H_INCLUDED
