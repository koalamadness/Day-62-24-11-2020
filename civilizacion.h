#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Civilizacion
{
private:
  string nombre;
  float ubX;
  float ubY;
  float punt;
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