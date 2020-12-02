#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <iostream>
#include <stdlib.h> 
#include <vector>
#include "civilizacion.h"

class Videogame
{
private:
  string nombreUs;
  vector<Civilizacion> arreglo;
public:
  Videogame();
  void agregarCivilizacion(const Civilizacion &c);
  void mostrar();

  Civilizacion getPrimero();
  Civilizacion getUltimo();

  void insertar(const Civilizacion &c, size_t pos);
  size_t total();
  void inicializar(const Civilizacion &c, size_t n);
  bool eliminar(const Civilizacion &c);
  void ordenar();
  void ordenarUbX();
  void ordenarUbY();
  void ordenarPunt();

  Civilizacion* buscar(const Civilizacion& c);

  void setNombreUs(const string& nus);
  string getNombreUs();

  friend Videogame& operator<<(Videogame& vid, const Civilizacion& c)
  {
    vid.agregarCivilizacion(c);

    return vid;
  }

  class Exception : public std::exception 
  {
  private:
    std::string msg;
  public:
    explicit Exception(const char* message) : msg(message) { }

    explicit Exception(const std::string& message) : msg(message) { }

    virtual ~Exception() throw () { }

    virtual const char* what() const throw () {return msg.c_str();}
  };
};

#endif