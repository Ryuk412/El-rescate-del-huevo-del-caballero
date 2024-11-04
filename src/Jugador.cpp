#include "Jugador.h"

string Jugador::getNombre()const{return _nombre;}
int Jugador::getPuntaje()const{return _puntaje;}
int Jugador::getNivel()const{return _nivel;}

void Jugador::setNombre(const string &n){_nombre=n;}
void Jugador::setPuntaje(int p){_puntaje=p;}
void Jugador::setNivel(int nv){_nivel=nv;}

void Jugador::Mostrar() const {
        cout << "Nombre: " << _nombre << endl;
        cout << "Puntaje: " << _puntaje << endl;
        cout << "Nivel: " << _nivel << endl;
}
