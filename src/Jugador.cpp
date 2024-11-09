#include "Jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

//getters(metodos q nos permiten acceder a los valores de los atributos privados de la clase jugador)
std::string Jugador::getNombre()const {return _nombre;}
int Jugador::getPuntaje()const {return _puntaje;}
int Jugador::getNivel()const {return _nivel;}

//setters(metodos que nos permiten modificar los valores de los atributos privados)
void Jugador::setNombre(const std::string &n){_nombre = n;}
void Jugador::setPuntaje(int p){_puntaje = p;}
void Jugador::setNivel(int nv){ _nivel = nv;}

void Jugador::Mostrar() const{
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Puntaje: "<<_puntaje<<endl;
    cout<<"Nivel: "<<_nivel<<endl;
}

// guarda los datos del jugador en el archivo
void Jugador::escribirEnArchivo(FILE *pArchivo)const{ ///recibe como parametro el puntero de archivo

    size_t longitud = _nombre.length();///longitud del nombre

    fwrite(&longitud, sizeof(longitud), 1, pArchivo);///escribe la longitud del nombre al archivo
    fwrite(_nombre.c_str(), sizeof(char), longitud, pArchivo);///escribe el nombre (caracter por caracter)
    fwrite(&_puntaje, sizeof(_puntaje), 1, pArchivo);///escribe el puntaje
    fwrite(&_nivel, sizeof(_nivel), 1, pArchivo);///escribe el nivel
}

///verifica que los datos del jugador haya hayan sido recbidos correctamente y sin ningun dato perdido
bool Jugador::leerDeArchivo(FILE *pArchivo){

    size_t longitud;///lee la longitud del nombre

    ///verificacion de que si se leyo el dato
    if(fread(&longitud, sizeof(longitud), 1, pArchivo) != 1){
        return false;
    }

    /// 1- lee el nombre
    char *caracteresDelNombre = new char[longitud + 1]; ///se crea de una variable con memoria dinamica para el nombre + \0

    if(fread(caracteresDelNombre, sizeof(char), longitud, pArchivo) != longitud){
        delete[] caracteresDelNombre; ///libera el espacio de memoria si algo salio mal
        return false;
    }

    caracteresDelNombre[longitud]='\0';///guarda \0 al final del nombre

    _nombre = std::string(caracteresDelNombre);///le asigna al nombre \0

    delete[] caracteresDelNombre;///libera el espacio de memoria

    /// 2- lee el puntaje y el nivel
    if(fread(&_puntaje, sizeof(_puntaje), 1, pArchivo) != 1){return false;}
    if(fread(&_nivel, sizeof(_nivel), 1, pArchivo) != 1){return false;}

    /// 3 - si todo salio bien devolvera TRUE
    return true;
}

