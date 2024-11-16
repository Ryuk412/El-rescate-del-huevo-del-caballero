#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>

class Jugador{
private:
    std::string _nombre="";
    int _puntaje=0;
    int _nivel=1;

public:

    std::string getNombre() const;
    int getPuntaje() const;
    int getNivel() const;

    void setNombre(const std::string &n);
    void setPuntaje(int p);
    void setNivel(int nv);

    void escribirEnArchivo(FILE *pArchivo) const;
    bool leerDeArchivo(FILE *pArchivo);
};

#endif // JUGADOR_H
