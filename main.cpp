#include <iostream>
#include "videogame.h"
#include "menu.h"
#include "menuCiv.h"

int main() {
  unsigned int op;
  size_t n;
  float myFloat;
  Menu myMenu;
  size_t myPos;
  Videogame myVid;
  string myString;
  Civilizacion myCiv;

  while(myMenu.getBandera() != false)
  {
    myMenu.printMenu();

    cin >> op; 
    myMenu.setOpcion(op);

    switch(myMenu.getOpcion())
    {
      case 1:
      {  
        cout << "Escriba el nombre de usuario: " << endl;
        cin.ignore();
        getline(cin, myString);
        myVid.setNombreUs(myString);
        cin.ignore();
        break;
      }

      case 2:
      {
        cin.ignore();
        cin >> myCiv;

        myVid.agregarCivilizacion(myCiv);

        break;
      }

      case 3:
      {        
        cin.ignore();
        cin >> myCiv;

        cout << "Posición: ";
        cin >> myPos; cin.ignore();

        if(myPos >= myVid.total())
        {
          cout << "Posición invalida" << endl;
        }
        else 
        {
          myVid.insertar(myCiv, myPos);
        }

        break;
      }

      case 4:
      { 
        cin.ignore();
        cin >> myCiv;

        cout << "Tamaño: ";
        cin >> n; cin.ignore();

        myVid.inicializar(myCiv, n);

        break;
      }

      case 5:
      {
        cout << left;
        cout << setw(10) << "Nombre";
        cout << setw(20) << "Ubicación en X";
        cout << setw(20) << "Ubicación en Y";
        cout << setw(15) << "Puntuación";
        cout << endl;
      
        cout << myVid.getPrimero();
        cout << endl;
        break;
      }

      case 6:
      {
        cout << left;
        cout << setw(10) << "Nombre";
        cout << setw(20) << "Ubicación en X";
        cout << setw(20) << "Ubicación en Y";
        cout << setw(15) << "Puntuación";
        cout << endl;
      
        cout << myVid.getUltimo();
        cout << endl;
        break;
      }

      case 7:
      {
        cout << "Elija una opción: " << endl;
        cout << "1) Ordenar por nombre" << endl;
        cout << "2) Ordenar por ubicación en X" << endl;
        cout << "3) Ordenar por ubicación en Y" << endl;
        cout << "4) Ordenar por puntuación" << endl;

        cin.ignore();

        cin >> op;

        switch(op)
        {
          case 1:
          {
            myVid.ordenar();
            break;
          }
          case 2:
          {
            myVid.ordenarUbX();
            break;
          }
          case 3:
          {
            myVid.ordenarUbY();
            break;
          }
          case 4:
          {
            myVid.ordenarPunt();
            break;
          }
        }
        break;
      }

      case 8:
      {
        cin.ignore();

        cout << "Nombre de la civilización a eliminar: " << endl;

        getline(cin, myString);

        myCiv.setNombre(myString);        

        if(myVid.eliminar(myCiv))
        {
          cout << "Civilización eliminada" << endl;
        }
        else
        {
          cout << "Civilización no encontrada" << endl;
        }
        break;
      }

      case 9:
      {
        cin.ignore();

        cout << "Nombre de la civilización a buscar: " << endl;

        getline(cin, myString);

        myCiv.setNombre(myString);

        Civilizacion *ptr = myVid.buscar(myCiv);

        if (ptr == nullptr)
        {
          cout << "No encontrado" << endl;
        }
        else
        {
          cout << left;
          cout << setw(10) << "Nombre";
          cout << setw(20) << "Ubicación en X";
          cout << setw(20) << "Ubicación en Y";
          cout << setw(15) << "Puntuación";
          cout << endl;          
          cout << *ptr << endl;
        }        
        break;
      }
      
      case 10:
      {
        cin.ignore();

        cout << "Nombre de la civilización a modificar: " << endl;

        getline(cin, myString);

        myCiv.setNombre(myString);

        Civilizacion *ptr = myVid.buscar(myCiv);

        if (ptr == nullptr)
        {
          cout << "No encontrado" << endl;
        }
        else
        {
          cout << left;
          cout << setw(10) << "Nombre";
          cout << setw(20) << "Ubicación en X";
          cout << setw(20) << "Ubicación en Y";
          cout << setw(15) << "Puntuación";
          cout << endl;          
          cout << *ptr << endl;

          cout << "Nombre: ";
          getline(cin, myString);
          
          ptr->setNombre(myString);

          cout << "Ubicación en X: ";
          cin >> myFloat;

          ptr->setUbX(myFloat);

          cout << "Ubicación en Y: ";
          cin >> myFloat;
          
          ptr->setUbX(myFloat);

          cout << "Puntuación: ";
          cin >> myFloat;
          
          ptr->setPunt(myFloat);
        }             
        break;
      }

      case 11:
      {
        myVid.mostrar();
        break;
      }

      case 12:
      {
        cin.ignore();
        cout << "Nombre de la civilización a buscar: " << endl;

        getline(cin, myString);

        myCiv.setNombre(myString);

        Civilizacion *ptr = myVid.buscar(myCiv);

        if (ptr == nullptr)
        {
          cout << "No encontrado" << endl;
        }
        else
        {
          menu(*ptr);
        }                
        break;
      }      

      case 13:
      {
        myVid.respaldar();
        break;
      }

      case 14:
      {
        myVid.recuperar();    
        break;
      }      

      case 15:
      {
        myMenu.setBandera(false);        
        break;
      }

      default:
      {
        cout << "Opción no disponible \n";
        break;
      }
    }
  }
}