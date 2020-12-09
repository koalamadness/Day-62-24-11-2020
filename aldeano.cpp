#include "aldeano.h"

Aldeano::Aldeano() {}

void Aldeano::setNombre(const string &nom)
{
  nombre = nom;
}

string Aldeano::getNombre() const
{
  return nombre;
}

void Aldeano::setEdad(size_t ed)
{
  edad = ed;
}

size_t Aldeano::getEdad() const
{
  return edad;
}

void Aldeano::setGenero(const string &gen)
{
  genero = gen;
}

string Aldeano::getGenero() const
{
  return genero;
}

void Aldeano::setSalud(float sal)
{
  salud = sal;
}

float Aldeano::getSalud() const
{
  return salud;
}