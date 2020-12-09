#include "civilizacion.h"
#include <algorithm>
#include <fstream>

using namespace std;

Civilizacion::Civilizacion() { }
Civilizacion::Civilizacion(const string& n, 
              const float uX,
              const float uY, 
              const float p)
              
{
  nombre = n;
  ubX = uX;
  ubY = uY;
  punt = p;
}

void Civilizacion::setNombre(const string &n)
{
  nombre = n;
}

void Civilizacion::setUbX(const float uX)
{
  ubX = uX;
}

void Civilizacion::setUbY(const float uY)
{
  ubY = uY;
}

void Civilizacion::setPunt(const float p)
{
  punt = p;
}

string Civilizacion::getNombre()
{
  return nombre;
}

float Civilizacion::getUbX()
{
  return ubX;
}

float Civilizacion::getUbY()
{
  return ubY;
}

float Civilizacion::getPunt()
{
  return punt;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
  aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
  aldeanos.push_front(a);
}

void Civilizacion::print()
{
  for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
  {
    cout << *it << endl;
  }
}

void Civilizacion::eliminarNombre(const string &nombre)
{
  for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
  {
    Aldeano &a = *it;

    if(nombre == a.getNombre())
    {
      aldeanos.erase(it);
      break;
    }
  }  
}

void Civilizacion::eliminarSalud(float sal)
{
  aldeanos.remove_if([sal](const Aldeano &a){ return a.getSalud() < sal;});
}

bool comparador(const Aldeano &a)
{
  return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
  aldeanos.remove_if(comparador);
}

void Civilizacion::ordenarNombre()
{
  aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
  return a1.getEdad() > a2.getEdad();
}

void Civilizacion::ordenarEdad()
{
  aldeanos.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud()
{
  aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscar(const Aldeano& a)
{
  auto it = find(aldeanos.begin(), aldeanos.end(), a);

  if (it == aldeanos.end())
  {
    return nullptr;
  }
  else 
  {
    return &(*it);
  }
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream aldeanos_arc(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanos_arc << aldeano.getNombre() << endl;
        aldeanos_arc << aldeano.getEdad()   << endl;
        aldeanos_arc << aldeano.getGenero() << endl;
        aldeanos_arc << aldeano.getSalud()  << endl;
    }
    aldeanos_arc.close();
}

void Civilizacion::recuperar_aldeanos(const string &nomCiv)
{
  ifstream archivo(nomCiv + ".txt");
  if (archivo.is_open())
  {
    string temp;
    size_t edad;
    float salud;
    Aldeano a;

    while(true)
    {
      getline(archivo, temp);
      if (archivo.eof()) 
      {
        break;
      }
      a.setNombre(temp);

      getline(archivo, temp);
      edad = stoi(temp);
      a.setEdad(edad);

      getline(archivo, temp);
      a.setGenero(temp);
      
      getline(archivo, temp);
      salud = stof(temp);
      a.setSalud(salud);

      agregarFinal(a);
    }
  }
  archivo.close();
}