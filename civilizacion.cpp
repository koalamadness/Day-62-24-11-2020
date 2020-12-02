#include "civilizacion.h"

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