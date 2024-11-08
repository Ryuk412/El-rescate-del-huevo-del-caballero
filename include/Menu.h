#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
       void nuevaPartida();
       void historia(bool empezarG);
       void cargarPartida();
       void jugar(bool estadoM);
       void opciones();
       void creditos();
       void salir();

  //  protected:
    private:
    bool _estado=false;
    bool _empezar=false;


};

#endif // MENU_H
