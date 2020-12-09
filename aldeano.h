#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{
private:
  string nombre;
  size_t edad;
  string genero;
  float salud;
public:
  Aldeano();
  
  void setNombre(const string &nom);
  string getNombre() const; 

  void setEdad(size_t ed);
  size_t getEdad() const;

  void setGenero(const string &gen);
  string getGenero() const;   

  void setSalud(float sal);
  float getSalud() const;

  friend istream& operator>>(istream& i, Aldeano& a)
  {
    cout << "Nombre: ";
    getline(cin, a.nombre);

    cout << "Edad: ";
    cin >> a.edad; cin.ignore();

    cout << "Género: ";
    getline(cin, a.genero);
    
    cout << "Salud: ";
    cin >> a.salud;

    cin.ignore(numeric_limits<streamsize>::max(), '\n' );

    return i;
  }

  friend ostream& operator<<(ostream &out, const Aldeano &a)
  {
    out << left;
    out << setw(10) << a.nombre;
    out << setw(8) << a.edad;
    out << setw(8) << a.genero;  
    out << setw(8) << a.salud;
    return out;
  }

  bool operator<(const Aldeano &a) const
  {
    return nombre < a.getNombre();
  }

  bool operator<(const Aldeano &a) 
  {
    return nombre < a.getNombre();
  }

  bool operator==(const Aldeano& a)
  {
    return nombre == a.nombre;
  }

  bool operator==(const Aldeano& a) const
  {
    return nombre == a.nombre;
  }  

};
#endif