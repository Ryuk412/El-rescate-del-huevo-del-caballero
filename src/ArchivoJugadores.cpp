/**

    fseek(vinculo con el archivo, cantidad de bytes que me quiero
            desplazar, desde donde);

    0 = SEEK_SET: desde el principio
    1 = SEEK_CUR: desde la posicion actual
    2 = SEEK_END: desde el end of file (eof), es decir, el final del
                    archivo.

    FSEEK: (busca)

     fseek(p, 0, 2); aca se posiciona directamente al final del archivo obteniendo su longitud

    --------------------------------------------------------------

    FTELL: (dice)

    ftell(vinculo con mi archivo): devuelve la cantidad de bytes
        desde el principio del archivo hasta la posicion actual.

     int tam=ftell(p);
*/

#include "ArchivoJugadores.h"
#include <iostream>
#include <cstring>

using namespace std;

ArchivoJugadores::ArchivoJugadores(const std::string &n){
    nombre=n;
}

int ArchivoJugadores::contarRegistro(){
    FILE *p;
    p = fopen(nombre.c_str(), "rb");
    if(p==nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam / sizeof(Jugador);
}
bool ArchivoJugadores::grabarRegistro(const Jugador &jugador){
    FILE *p;
    p=fopen(nombre.c_str(),"ab");
    if(p==nullptr){
        return false;
    }
    fwrite(&jugador, sizeof(Jugador), 1, p);
    fclose(p);
    return true;
}

void ArchivoJugadores::vaciar() {
    FILE* p = fopen(nombre.c_str(), "wb"); // Usa c_str() para obtener el puntero
    if (p == nullptr) {
        cout << "Error al vaciar el archivo." << endl;
        return;
    }
    fclose(p);
    cout << "Se eliminaron todos los registros." << endl;
}
