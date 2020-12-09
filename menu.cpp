#include "menu.h"

using namespace std;

Menu::Menu() { }
Menu::Menu(const Menu& m) : opcion(m.opcion), bandera(m.bandera) { }

void Menu::printMenu()
{
  cout << "Elija una opción: " << endl;
  cout << "1) Nombre de usuario" << endl;
  cout << "2) Agregar civilización" << endl;
  cout << "3) Insertar civilización" << endl;
  cout << "4) Crear civilizaciones" << endl;
  cout << "5) Primera civilización" << endl;
  cout << "6) Última civilización" << endl;
  cout << "7) Ordenar" << endl;
  cout << "8) Eliminar civilización" << endl;
  cout << "9) Buscar" << endl;
  cout << "10) Modificar" << endl;
  cout << "11) Resumen" << endl;
  cout << "12) Buscar civilización" << endl;
  cout << "13) Respaldar civilizaciones" << endl;  
  cout << "14) Recuperar civilizaciones" << endl;    
  cout << "15) Salir" << endl;
}

unsigned int Menu::getOpcion() {return opcion;}
bool Menu::getBandera() {return bandera;}

void Menu::setOpcion(unsigned int opc) {opcion = opc;}
void Menu::setBandera(bool b) {bandera = b;}