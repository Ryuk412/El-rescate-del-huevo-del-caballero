#ifndef ARCHIVOJUGADORES_H_INCLUDED
#define ARCHIVOJUGADORES_H_INCLUDED

#include "Jugador.h"
#include <string>

class ArchivoJugadores {
private:
    std::string nombre;///atributo privado que guarda el nombre del jugador

public:
    ArchivoJugadores(const std::string &n = "jugadores.dat");///cnstructor donde se crea el archivo / const para que el metodo no modifique el valor del objeto
    int contarRegistro();
    bool grabarRegistro(const Jugador &jugador);///guarda los registros en el archivo de jugadores.dat
    std::string listarRegistro(); ///devuelve los registros del archivo en cadena de texto
    void vaciar();
};

#endif // ARCHIVOJUGADORES_H_INCLUDED
