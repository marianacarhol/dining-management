#include "Persona.h"
#include <iostream>

  Persona::Persona(){};
  Persona::Persona(int r, Comida comida){
    rol=r;
    alimento=comida;
  }

  int Persona::getRol() { 
    return rol; 
  }

  void Persona::setRol(int r) {
    rol = r; 
  }

  bool Persona::esConsumidor() const{
    if(rol == 1){
      return true;
    }
    else{
      return false;
    }
  }

  int Persona::getTipoAlimento() {
        return alimento.getTipoAlimento();
    }

  int Persona::getCantAlimento() {
        return alimento.getCantAlimento();
    }
    
  Persona::~Persona(){}