#include "ArchivoJugadores.h"
#include <iostream>
#include <cstring>

using namespace std;


ArchivoJugadores::ArchivoJugadores(const std::string &n){
    nombre=n;
}

int ArchivoJugadores::contarRegistro(){
    FILE *p = fopen(nombre.c_str(), "rb");
    if (p == nullptr){return 0;}
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    if(tam==0){return 0;}
    return tam / sizeof(Jugador);
}

bool ArchivoJugadores::grabarRegistro(const Jugador &jugador){
    FILE *p = fopen(nombre.c_str(), "ab");
    if(p == nullptr){return false;}
    jugador.escribirEnArchivo(p);
    fclose(p);
    return true;
}

std::string ArchivoJugadores::listarRegistro(){
    FILE *p = fopen(nombre.c_str(), "rb");
    std::string registro;
    if (p == nullptr){return "";}

    Jugador jug;
    while(jug.leerDeArchivo(p)){
        registro += jug.getNombre() + "             " + std::to_string(jug.getPuntaje()) +" puntos              nivel " + std::to_string(jug.getNivel()) + "\n";
    }

    fclose(p);
    return registro;
}

void ArchivoJugadores::vaciar(){
    FILE* p = fopen(nombre.c_str(), "wb");///abre al archivo y como el archivo ya existe su contenido sera borrado
    if (p == nullptr){return;}
    fclose(p);
    cout<<"archivo vacio"<<endl;
}
