#ifndef Comedor_h
#define Comedor_h
#include "Persona.cpp"
#include <vector>
#include <string>
using namespace std;

class Comedor{
private:
  string nombre;
  vector <Persona> personas;
public:
  Comedor();
  void setPersona(Persona);
  int mostrarInventario();
  void agregarDonacion();
  int obtenerCantidadAlimentoPorTipo(int);
  int cantConsumidores();
  int cantDonadores();
  void leerFichero(const string& nombreFichero);
  void guardarFichero(const string& nombreFichero);

  ~Comedor();
};

#endif