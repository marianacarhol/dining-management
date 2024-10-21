#ifndef Persona_h
#define Persona_h
#include "Comida.cpp"
#include <iostream>
#include <string>
using namespace std;

class Persona{
private:
  int rol;
  Comida alimento;
public:
  Persona();
  Persona(int, Comida);
  bool esConsumidor() const;
  int getRol();
  void setRol(int);
  int getTipoAlimento() ;
  int getCantAlimento() ;
  ~Persona();
};

#endif