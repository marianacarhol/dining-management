#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "Comedor.h"

using namespace std;

int main(){
  cout << "Bienvenid@ al Comedor Comunitario Manos Solidarias\n Alimentando corazones, juntos, un plato a la vez"<< endl;
  Comedor comedor;
  comedor.leerFichero("Comedor.txt");
  
    int choice, a;
    do{
      cout << "Seleccione la opción que desea realizar. " << endl 
        << "1. Ver desglose de actividad"  << endl 
        << "2. Ver inventario" << endl
        << "3. Agregar Donación" << endl
        << "4. Terminar programa" << endl;
      cin >> choice;

      if (cin.fail() || choice < 1 || choice > 4){
        cout << "Introduce un valor válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      switch(choice) {
          case 1:
            cout << "***DESGLOSE DE ACTIVIDAD***" << endl
            << "Cantidad de consumidores:"<< comedor.cantConsumidores() << endl
            << "Cantidad de donadores:"<< comedor.cantDonadores()<< endl<< endl;
            break;
            
          case 2:
            cout << "***INVENTARIO***" << endl
            << comedor.mostrarInventario() << endl;
            break;

          case 3:
            cout << "***AGREGAR DONACIÓN***" << endl;
            comedor.agregarDonacion();
            break;

          case 4:
            cout << "***FIN DEL PROGRAMA***" << endl;
            break;
      }

      cout << "¿Desea volver al menú? (1. Si / 2. No)"<< endl;
      cin >> a;

      if (cin.fail() || a < 1 || a > 2){
        cout << "Introduce un valor válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
      
      if (a != 1) {
          choice = 4;
      }
      
    }while(choice!=4);

  comedor.guardarFichero("ComedorNuevo.txt");
      return 0;
  }
  