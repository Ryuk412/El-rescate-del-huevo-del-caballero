#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>

class Jugador{
private:
    std::string _nombre="";
    int _puntaje=0;

public:

    /**
    const: se usa para mas que nada controlar que los metodos
           (correspondiente) no alteren los valores de los atributos
           del objeto
    */

    //getters
    std::string getNombre() const; ///metodo de tipo string xq devuelve un string
    int getPuntaje() const;
    int getNivel() const;

    //setters
    void setNombre(const std::string &n);///establece un nuevo nomrbe para el jugador
    void setPuntaje(int p);///establece un nuevo puntaje para el jugador
    void setNivel(int nv);///establece un nuevo nivel

    void Mostrar() const;///muestra la info del jugador

    /**
    metodos que reciben de parametro un puntero(variable que tiene la direccion de memoria de otra variable)
    que los lleva al archivo
    */
    void escribirEnArchivo(FILE *pArchivo) const; ///guarda los datos del jugador al archivo
    bool leerDeArchivo(FILE *pArchivo); ///verifica que todos los datos fueron pasados correctamente al archivo + se le agrega \0 al nombre para que c++ lo identifique como caracter de texto
};

#endif // JUGADOR_H
