#include "ArchivoJugadores.h"
#include <iostream>
#include <cstring>

using namespace std;

/**
    constructor que recibe por referencia(la direccion de mem) una cadena
    de texto (nombre del archivo) y se la asigna al atributo
    'nombre' del objeto 'ArchivoJugadores'
*/
ArchivoJugadores::ArchivoJugadores(const std::string &n){
    nombre=n;
}

/// .c_str (puntero para los tipo string)

int ArchivoJugadores::contarRegistro(){
    FILE *p=fopen(nombre.c_str(), "rb");///abre el archivo con el nombre almacenado en 'nombre' usando el puntero FILE y lo abre en modo lectura(binaria)
    if (p == nullptr){///verifica si el archivo se abrio
        return 0;
    }
    fseek(p, 0, 2);///mueve el puntero de archivo al final(SEEK_END)
    int tam=ftell(p);///obtiene el tamaño del archivo
    fclose(p);///cierra el archivo
    return tam/sizeof(Jugador);///devuelve la cantidad de objetos jugador que estan almacenados en el archivo
}

bool ArchivoJugadores::grabarRegistro(const Jugador &jugador){///recibe el nombre del jugador desde jugador.h
    FILE *p;
    p=fopen(nombre.c_str(),"ab");///abre el archivo en modo append(agrega datos al final del archivo)
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
    std::string registro;///se crea el string xq la funcion tiene q devolver un std::String

    if (p == nullptr){
        return "";///devuelve una cadena vacia
    }

    Jugador jug;
    while(jug.leerDeArchivo(p)){
        registro += jug.getNombre() + "     " + std::to_string(jug.getPuntaje()) +" puntos     nivel " + std::to_string(jug.getNivel()) + "\n";
    }
    ///std::to_string convierte los int (niveles/puntajes) a string

    fclose(p);
    return registro;
}


void ArchivoJugadores::vaciar(){
    FILE* p = fopen(nombre.c_str(), "wb");///abre al archivo y como el archivo ya existe su contenido sera borrado
    if (p == nullptr) {
        cout << "Error al vaciar el archivo." << endl;
        return;
    }
    fclose(p);///cierra el archivo
    cout << "Se eliminaron todos los registros." << endl;
}
