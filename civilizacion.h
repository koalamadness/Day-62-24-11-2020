#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "aldeano.h"

using namespace std;

class Civilizacion
{
private:
  string nombre;
  float ubX;
  float ubY;
  float punt;
  list<Aldeano> aldeanos;
public:
  Civilizacion();
  Civilizacion(const string& n, 
              const float uX,
              const float uY, 
              const float p);

  void setNombre(const string& n);
  string getNombre();

  void setUbX(const float uX);
  float getUbX();

  void setUbY(const float uY);
  float getUbY();

  void setPunt(const float p);
  float getPunt();

  void agregarFinal(const Aldeano &a);
  void agregarInicio(const Aldeano &a); 

  void print();     

  void eliminarNombre(const string &nombre);
  void eliminarSalud(float sal);
  void eliminarEdad();  

  void ordenarNombre();
  void ordenarEdad();
  void ordenarSalud();  

  Aldeano* buscar(const Aldeano& a);  

  void respaldar_aldeanos();
  void recuperar_aldeanos(const string& nomCiv);

  friend ostream& operator<<(ostream& out, const Civilizacion& c)
  {
    out << left;
    out << setw(10) << c.nombre;
    out << setw(20) << c.ubX;
    out << setw(20) << c.ubY;
    out << setw(15) << c.punt;
    out << endl;
    return out;
  }
  
  friend istream& operator>>(istream& i, Civilizacion& c)
  {
    cout << "Nombre: ";
    getline(cin, c.nombre);

    cout << "Ubicación en X: ";
    cin >> c.ubX;

    cout << "Ubicación en Y: ";
    cin >> c.ubY;
    
    cout << "Puntuación: ";
    cin >> c.punt;

    cin.ignore(numeric_limits<streamsize>::max(), '\n' );

    return i;
  }

  bool operator==(const Civilizacion& c)
  {
    return nombre == c.nombre;
  }

  bool operator==(const Civilizacion& c) const
  {
    return nombre == c.nombre;
  }

  bool operator<(const Civilizacion& c)
  {
    return nombre < c.nombre;
  }
  
  bool operator<(const Civilizacion& c) const
  {
    return nombre < c.nombre;
  }  
  
};

#endif