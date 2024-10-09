#include "Comedor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

Comedor::Comedor() {}


void Comedor::setPersona(Persona p) {
    personas.push_back(p);
}

/////////////////////////////////////////////////////////////////
int Comedor::mostrarInventario() {
  cout << "Tipo de alimento: Bolsa de arroz " << endl
       << "Cantidad: " << obtenerCantidadAlimentoPorTipo(1) << endl << endl

       << "Tipo de alimento: Lata de atún " << endl
       << "Cantidad: " << obtenerCantidadAlimentoPorTipo(2) << endl << endl

       << "Tipo de alimento: Bolsa de frijoles " << endl
       << "Cantidad: " << obtenerCantidadAlimentoPorTipo(3) << endl << endl

       << "Tipo de alimento: Lata de legumbres " << endl
       << "Cantidad: ";
      return obtenerCantidadAlimentoPorTipo(4);
}

/////////////////////////////////////////////////////////////////
void Comedor::agregarDonacion(){
  int rol, tipoAlimento, cantAlimento;
  do{
    cout << "Ingrese el rol de la persona (1. Consumidor / 2. Donador): ";
    cin >> rol;
    if (cin.fail() || rol < 1 || rol > 2){
      cout << "Introduce un valor válido." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }while (cin.fail() || rol < 1 || rol > 2);

  
  //////////////////////////////

  do{
    cout << "Ingrese el tipo de alimento (1. Bolsa de arroz / 2. Lata de atún / 3. Bolsa de frijoles / 4. Lata de legumbres): ";
    cin >> tipoAlimento;
    if (cin.fail() || tipoAlimento<1 || tipoAlimento>4){
      cout << "Introduce un valor válido." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }while (cin.fail() || tipoAlimento<1 || tipoAlimento>4);
  
  //////////////////////////////
  
  do{
    cout << "Ingrese la cantidad de alimento (pza): ";
    cin >> cantAlimento;
    if (cin.fail() || cantAlimento<=0){
      cout << "Introduce un valor válido." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }while (cin.fail() || cantAlimento<=0);

  
    Comida c(tipoAlimento, cantAlimento);
    Persona p(rol, c);
    personas.push_back(p);
  
}

/////////////////////////////////////////////////////////////////
int Comedor::obtenerCantidadAlimentoPorTipo(int tipo) {
    int cantidadTotal = 0;
    for (Persona persona : personas) {
        if (persona.getTipoAlimento() == tipo) {
            cantidadTotal += persona.getCantAlimento();
        }
    }
    return cantidadTotal;
}

/////////////////////////////////////////////////////////////////
int Comedor::cantConsumidores() {
    int cantConsumidores = 0;
    for (const auto& persona : personas) {
        if (persona.esConsumidor()) {
            cantConsumidores++;
        }
    }
    return cantConsumidores;
}

/////////////////////////////////////////////////////////////////
int Comedor::cantDonadores() {
    int cantDonadores = 0;
    for (const auto& persona : personas) {
        if (!persona.esConsumidor()) {
            cantDonadores++;
        }
    }
    return cantDonadores;
}

/////////////////////////////////////////////////////////////////
void Comedor::leerFichero(const string& nombreFichero) {
    ifstream archivoEntrada(nombreFichero);

    if (archivoEntrada.is_open()) {
        int cRol, cTipoAlimento, cCantAlimento;

        while (archivoEntrada >> cRol >> cTipoAlimento >> cCantAlimento) {
            Comida c(cTipoAlimento, cCantAlimento);
            Persona p(cRol, c);
            setPersona(p); 
        }

        archivoEntrada.close();
    } else {
       cerr << "Error al abrir el archivo." << endl;
    }
}

//////////////////////////////////////////////////
void Comedor::guardarFichero(const string& nombreFichero) {
ofstream archivoSalida("ComedorNuevo.txt");
int numero= personas.size();
  if (archivoSalida.is_open()) {
      for (int i = 0; i < numero; i++) {
        archivoSalida << personas[i].getRol() <<" " << personas[i].getTipoAlimento() << " "<< personas[i].getCantAlimento() <<endl;
      }
  
      archivoSalida.close();
  } else {
     cerr << "Error al abrir el archivo." << endl;
  }
}

Comedor::~Comedor() {}
