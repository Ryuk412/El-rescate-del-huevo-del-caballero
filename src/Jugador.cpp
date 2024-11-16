#include "Jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

std::string Jugador::getNombre()const {return _nombre;}
int Jugador::getPuntaje()const {return _puntaje;}
int Jugador::getNivel()const {return _nivel;}

void Jugador::setNombre(const std::string &n){_nombre = n;}
void Jugador::setPuntaje(int p){_puntaje = p;}
void Jugador::setNivel(int nv){ _nivel = nv;}

///guarda los datos del jugador en el archivo
void Jugador::escribirEnArchivo(FILE *pArchivo)const{ ///recibe como parametro el puntero de archivo

    if(pArchivo == nullptr){
        return;
    }
    size_t longitud = _nombre.length();///longitud del nombre

    fwrite(&longitud, sizeof(longitud), 1, pArchivo);///escribe la longitud del nombre al archivo
    fwrite(_nombre.c_str(), sizeof(char), longitud, pArchivo);///escribe el nombre (caracter por caracter)
    fwrite(&_puntaje, sizeof(_puntaje), 1, pArchivo);///escribe el puntaje
    fwrite(&_nivel, sizeof(_nivel), 1, pArchivo);///escribe el nivel
}

///verifica que los datos del jugador haya hayan sido recbidos correctamente y sin ningun dato perdido
bool Jugador::leerDeArchivo(FILE *pArchivo){

    if (pArchivo == nullptr){return false;}

    size_t longitud;

    if(fread(&longitud, sizeof(longitud), 1, pArchivo) != 1){return false;}

    char *caracteresDelNombre = new(std::nothrow) char[longitud + 1];
    if(caracteresDelNombre == nullptr){return false;}

    if(fread(caracteresDelNombre, sizeof(char), longitud, pArchivo) != longitud){
        delete[] caracteresDelNombre;
        return false;
    }

    caracteresDelNombre[longitud]= '\0';
    _nombre = std::string(caracteresDelNombre);

    delete[] caracteresDelNombre;

    if(fread(&_puntaje, sizeof(_puntaje), 1, pArchivo) != 1){return false;}

    if(fread(&_nivel, sizeof(_nivel), 1, pArchivo) != 1){return false;}

    return true;
}
