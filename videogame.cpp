#include "videogame.h"
#include <fstream>
#include <algorithm>

using namespace std;

Videogame::Videogame()
{
  
}

void Videogame::agregarCivilizacion(const Civilizacion& c)
{
  arreglo.push_back(c);
}

void Videogame::mostrar()
{
  cout << left;
  cout << setw(10) << "Nombre";
  cout << setw(20) << "Ubicación en X";
  cout << setw(20) << "Ubicación en Y";
  cout << setw(15) << "Puntuación";
  cout << endl;

  for (size_t i = 0; i < arreglo.size(); i++)
  { 
    Civilizacion &ci = arreglo[i];

    cout << ci;

    cout << endl;
  }
}

void Videogame::insertar(const Civilizacion &c, size_t pos)
{
  arreglo.insert(arreglo.begin() + pos, c);
}

size_t Videogame::total()
{
  return arreglo.size();
}

void Videogame::inicializar(const Civilizacion &c, size_t n)
{
  arreglo = vector<Civilizacion>(n, c);
}

bool Videogame::eliminar(const Civilizacion &c)
{
  int index;
  auto it = find(arreglo.begin(), arreglo.end(), c);

  if (it == arreglo.end())
  {
    return false;
  }
  else 
  {
    index = it - arreglo.begin();
    arreglo.erase(arreglo.begin() + index);
    return true;
  }

}

void Videogame::setNombreUs(const string& nus)
{
  nombreUs = nus;
}

string Videogame::getNombreUs()
{
  return nombreUs;
}

Civilizacion Videogame::getPrimero()
{
  if(total())
  {
    return arreglo.front();
  }
  else
  {
    throw Exception("Vector vacío, getPrimero"); 
  }
}

Civilizacion Videogame::getUltimo()
{
  if(total())
  {
    return arreglo.back();
  }
  else
  {
    throw Exception("Vector vacío, getPrimero"); 
  }
}

void Videogame::ordenar()
{
  sort(arreglo.begin(), arreglo.end());
}

void Videogame::ordenarUbX()
{
  sort(arreglo.begin(), arreglo.end(), 
  [](Civilizacion c1, Civilizacion c2){return c1.getUbX() < c2.getUbX();});
}

void Videogame::ordenarUbY()
{
  sort(arreglo.begin(), arreglo.end(), 
  [](Civilizacion c1, Civilizacion c2){return c1.getUbY() < c2.getUbY();});
}

void Videogame::ordenarPunt()
{
  sort(arreglo.begin(), arreglo.end(), 
  [](Civilizacion c1, Civilizacion c2){return c1.getPunt() < c2.getPunt();});
}

Civilizacion* Videogame::buscar(const Civilizacion& c)
{
  auto it = find(arreglo.begin(), arreglo.end(), c);

  if (it == arreglo.end())
  {
    return nullptr;
  }
  else 
  {
    return &(*it);
  }
}