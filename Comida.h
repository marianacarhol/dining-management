#ifndef Comida_h
#define Comida_h
#include <string>
using namespace std;

class Comida {
private:
  int tipoAlimento;
  int cantAlimento;

public:
  Comida();
  Comida(int, int);
  int getTipoAlimento();
  void setTipoAlimento(int);
  int getCantAlimento();
  void setCantAlimento(int);
  ~Comida();
};

#endif