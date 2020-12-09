#include "civilizacion.h"

void menu(Civilizacion &civ)
{
  unsigned int op;

  while(op != 0)
  {
    cout << "1) Agregar Aldeano" << endl;
    cout << "2) Eliminar Aldeano" << endl;
    cout << "3) Clasificar Aldeanos" << endl;
    cout << "4) Buscar Aldeano" << endl;
    cout << "5) Modificar Aldeano" << endl;
    cout << "6) Mostrar Aldeanos" << endl;  
    cout << "0) Salir" << endl;      

    cin >> op; cin.ignore();

    switch(op)
    {
      case 1:
      {
        Aldeano a;
        cout << "1) Agregar el objeto aldeano al inicio" << endl;
        cout << "2) Agregar el objeto aldeano al final" << endl;

        cin >> op; cin.ignore();

        if(op == 1)
        {
          cin >> a;
          civ.agregarInicio(a);
          
          civ.setPunt(civ.getPunt() + 100);
        }
        else if(op == 2)
        {
          cin >> a;
          civ.agregarFinal(a);

          civ.setPunt(civ.getPunt() + 100);
        }

        break;
      }

      case 2:
      {
        cout << "1) Eliminar Nombre" << endl;
        cout << "2) Eliminar Salud = s" << endl;            
        cout << "3) Eliminar Edad" << endl;      

        cin >> op; cin.ignore();

        if(op == 1)
        {
          string nombre;

          cout << "Nombre: ";
          getline(cin, nombre);

          civ.eliminarNombre(nombre);
        }
        else if(op == 2)
        {
          float salud;

          cout << "Salud: ";
          cin >> salud; cin.ignore();

          civ.eliminarSalud(salud);
        }        
        else if(op == 3)
        {
          civ.eliminarEdad();  
        }
        break;
      }

      case 3:
      {
        cout << "1) Clasificar por nombre" << endl;
        cout << "2) Clasificar por edad" << endl;  
        cout << "3) Ordenar por salud" << endl; 

        cin >> op; cin.ignore();        

        if(op == 1)
        {
          civ.ordenarNombre();
        }
        else if(op == 2)
        {
          civ.ordenarEdad();
        }        
        else if(op == 3)
        {
          civ.ordenarSalud();
        }

        break;
      }

      case 4:
      {
        
        Aldeano a;
        string nombre;

        cout << "Nombre del aldeano a buscar: ";

        getline(cin, nombre);

        a.setNombre(nombre);

        Aldeano *ptr = civ.buscar(a);

        if (ptr == nullptr)
        {
          cout << "No encontrado" << endl;
        }
        else
        {
          cout << left;
          cout << setw(10) << "Nombre";
          cout << setw(8) << "Edad";
          cout << setw(8) << "Género";
          cout << setw(8) << "Salud";
          cout << endl;          
          cout << *ptr << endl;
        }              
        break;
      }

      case 5:
      {
        Aldeano a;
        string nombre;
        string genero;
        size_t ed;
        float sal;

        cout << "Nombre del aldeano a modificar: " << endl;

        getline(cin, nombre);

        a.setNombre(nombre);

        Aldeano *ptr = civ.buscar(a);

        if (ptr == nullptr)
        {
          cout << "No encontrado" << endl;
        }
        else
        {
          cout << left;
          cout << setw(10) << "Nombre";
          cout << setw(8) << "Edad";
          cout << setw(8) << "Género";
          cout << setw(8) << "Salud";
          cout << endl;          
          cout << *ptr << endl;

          cout << "Nombre: ";
          getline(cin, nombre);
          
          ptr->setNombre(nombre);

          cout << "Edad: ";
          cin >> ed; cin.ignore();

          ptr->setEdad(ed);

          cout << "Género: ";
          getline(cin, genero);
          
          ptr->setGenero(genero);

          cout << "Salud: ";
          cin >> sal;
          
          ptr->setSalud(sal);
        }          
        break;           
      }

      case 6:
      {
        civ.print();
        break;
      }

      case 0:
      {
        break;
      }
    }
  }
}