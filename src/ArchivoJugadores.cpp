#include "ArchivoJugadores.h"
#include <iostream>
#include <cstring>

using namespace std;


ArchivoJugadores::ArchivoJugadores(const std::string &n){
    nombre=n;
}

int ArchivoJugadores::contarRegistro(){
    FILE *p=fopen(nombre.c_str(), "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Jugador);
}

bool ArchivoJugadores::grabarRegistro(const Jugador &jugador){///recibe el nombre del jugador desde jugador.h
    FILE *p;
    p=fopen(nombre.c_str(),"ab");
    if(p==nullptr){
        cout<<"grabarRegistro: error al abrir el archivo para grabar"<<endl;
        return false;
    }
    jugador.escribirEnArchivo(p);
    fclose(p);
    return true;
}

std::string ArchivoJugadores::listarRegistro(){
    FILE *p = fopen(nombre.c_str(), "rb");
    std::string registro;

    if (p == nullptr){
        return "";
    }

    Jugador jug;
    while(jug.leerDeArchivo(p)){
        registro += jug.getNombre() + "     " + std::to_string(jug.getPuntaje()) +" puntos\n";
    }

    fclose(p);
    return registro;
}


void ArchivoJugadores::vaciar(){
    FILE* p = fopen(nombre.c_str(), "wb");///abre al archivo y como el archivo ya existe su contenido sera borrado
    if (p == nullptr) {
        cout << "Error al vaciar el archivo."<<endl;
        return;
    }
    fclose(p);
    cout << "Se eliminaron todos los registros."<<endl;
}
