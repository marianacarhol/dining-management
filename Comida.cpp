#include "Comida.h"
#include <iostream>

Comida::Comida(){};
Comida::Comida(int tipoAlim, int cantAlim) {
  tipoAlimento = tipoAlim;
  cantAlimento = cantAlim;
};

void Comida::setTipoAlimento(int tipoAlim) {
  tipoAlimento = tipoAlim; 
};

int Comida::getTipoAlimento() { 
  return tipoAlimento; 
};

void Comida::setCantAlimento(int cantAlim) { 
  tipoAlimento = cantAlim; 
};

int Comida::getCantAlimento() { 
  return cantAlimento; 
};

Comida::~Comida(){}