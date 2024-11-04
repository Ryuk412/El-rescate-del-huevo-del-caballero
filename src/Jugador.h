#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador{
private:
    string _nombre;
    int _puntaje=0;
    int _nivel=1;

public:
    string getNombre()const;
    int getPuntaje()const;
    int getNivel()const;

    void setNombre(const string &n);
    void setPuntaje(int p);
    void setNivel(int nv);

    void Mostrar()const;

};

#endif // JUGADOR_H
