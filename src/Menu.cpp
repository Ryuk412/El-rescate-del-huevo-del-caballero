#include "Menu.h"
#include "iostream"
Menu::Menu()
{
    int M;
    std::cout<<"menu juego "<<std::endl;
        std::cout<<"-----------------"<<std::endl;
        std::cout<<"1 juego"<<std::endl;
        std::cout<<"2 opciones"<<std::endl;
        std::cout<<"0 salir "<<std::endl;
        std::cout<<"-----------------"<<std::endl;
        std::cin>>M;



switch (M)
{
case 1:
    _estado=true;
    jugar(_estado);
    break;
case 2:
    opciones();
    break;

case 0:
            std::cout<<"Gracias por jugar"<<std::endl;
            system("pause");
            exit(0);
    break;
default:
    break;
}





}

//Menu::~Menu()
//{
//    //dtor
//}

 void Menu::nuevaPartida(){

std::cout<<"ESTAMOS EN LA NUEVA PARTIDA";


 }
  void Menu::cargarPartida(){

  std::cout<<"ESTAMOS EN cagar partida ";

  }
    void Menu::jugar(bool estado)
    {
        int M;
        std::cout<<"menu juego "<<std::endl;

        std::cout<<"1 para nueva partida"<<std::endl;
        std::cout<<"2 para cargar partida"<<std::endl;
        std::cin>>M;
        switch (M)
        {
        case 1:
            if (_estado==true){
            nuevaPartida();
            }

            std::cout<<"no funciona nueva partida";
            break;
         case 2:
             cargarPartida();
            break;
            return;
        default:
            break;
            _estado=false;
        }


    }
//    void Menu::opciones();
//   void Menu::creditos();
//   void Menu::salir();
