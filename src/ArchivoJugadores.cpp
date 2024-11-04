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

