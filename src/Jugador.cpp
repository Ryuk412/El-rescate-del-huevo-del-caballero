#include "Jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

///getters(metodos q nos permiten acceder a los valores de los atributos privados de la clase jugador)
std::string Jugador::getNombre()const {return _nombre;}
int Jugador::getPuntaje()const {return _puntaje;}
int Jugador::getNivel()const {return _nivel;}

///setters(metodos que nos permiten modificar los valores de los atributos privados)
void Jugador::setNombre(const std::string &n){_nombre = n;}
void Jugador::setPuntaje(int p){_puntaje = p;}
void Jugador::setNivel(int nv){ _nivel = nv;}

void Jugador::Mostrar() const{
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Puntaje: "<<_puntaje<<endl;
    cout<<"Nivel: "<<_nivel<<endl;
}



/// metodo: guarda los datos del jugador en el archivo
void Jugador::escribirEnArchivo(FILE *pArchivo)const{ ///recibe como parametro el puntero al archivo de tipo FILE

    size_t longitud = _nombre.length();///longitud del nombre

    /**
        longitud tiene el tamaño de _nombre que es un string


        .length() metodo de la clase string que devuelve el numero de caracteres que tiene la variable _nombre

                  longitud es una variable de tipo size_t que guarda el valor que pasado por .length()


        size_t  es un tipo de dato SIN SIGNO(no permite nros negativos solo nros positivos o cero)
                que se usa para almacenar grandes cantidades de elementos

                almacena la cantidad de caracteres de la variable tipo string _nombre
                menos su caracter nulo \0

        Ejemplo: 'hola'

        size_t longitud =_nombre.length() // longitud=4
    */

    fwrite(&longitud, sizeof(longitud), 1, pArchivo);///escribe la longitud del nombre al archivo
    fwrite(_nombre.c_str(), sizeof(char), longitud, pArchivo);///escribe el nombre (caracter por caracter)
    fwrite(&_puntaje, sizeof(_puntaje), 1, pArchivo);///escribe el puntaje
    fwrite(&_nivel, sizeof(_nivel), 1, pArchivo);///escribe el nivel


    /**
        & -> es para obtener la direccion de memoria de las variables
             y pasarlas como punteros a fwrite

    .c_str() -> puntero para los tipo string (devuelve un puntero al arrelo de caracteres)

        fwrite (se usa para escribir datos a un archivo)

        fwrite( [puntero al dato que quiero escribir en el archivo],
                [el tamaño del elemento que se llevara al archiv],
                [cant de elementos que voy a escribir en el archivo],
                [el puntero al archivo donde quiero guardar ese dato]);
    */
}

///metodo: lee los datos del jugador desde el archivo - es de tipo bool para indicar si la operacion lectura desde el archivo fue exitosa

/// esta funcion se creo para verificar que los datos del jugador fueron recbidos correctamente y sin ningun dato perdido
bool Jugador::leerDeArchivo(FILE *pArchivo){


    size_t longitud;///lee la longitud del nombre

    ///verificacion de que si se leyo el dato
    if(fread(&longitud, sizeof(longitud), 1, pArchivo) != 1){
        return false;
    }
    /// 1- lee el nombre

    ///se crea de una variable con memoria dinamica para el nombre + \0(se le agrega el nulo para q c++ lo identifique al arreglo como una cadena de txt)
    char *caracteresDelNombre = new char[longitud + 1];

    ///se usar primero char xq fread es una funcion de bajp nivel para leer bytes de un archivo
    ///y por predeterminado trabaja con punteros en este caso con un puntero a char
    if(fread(caracteresDelNombre, sizeof(char), longitud, pArchivo) != longitud){
        delete[] caracteresDelNombre; ///libera el espacio de memoria si algo salio mal
        return false;///si no leyo el nombre completo devolvera false
    }

    caracteresDelNombre[longitud]='\0';///guarda \0 al final del nombre donde actualmente seria un espacio vacio para ser reemplazado por este

    _nombre = std::string(caracteresDelNombre); ///le asigna al nombre \0

    delete[] caracteresDelNombre;///libera el espacio de memoria

    /// 2- lee el puntaje y el nivel
    if(fread(&_puntaje, sizeof(_puntaje), 1, pArchivo) != 1){return false;}
    if(fread(&_nivel, sizeof(_nivel), 1, pArchivo) != 1){return false;}

    /// 3 - si todo salio bien devolvera TRUE
    return true;
}

