#include <iostream>
#include "analizador_programa.h"

int main(int argc, char *argv[]) {
  AnalizadorPrograma prueba1(argv[1]);
  prueba1.AnalizarPrograma();
  prueba1.VolcarResultados(argv[2]);
  return 0;
}