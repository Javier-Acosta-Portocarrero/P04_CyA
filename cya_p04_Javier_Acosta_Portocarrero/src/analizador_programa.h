#include <iostream>
#include <regex>
#include <vector>
#include <fstream>
#include "bucle.h"
#include "comentario.h"
#include "variable.h"

class AnalizadorPrograma {    
 public:
  AnalizadorPrograma(std::string fichero_entrada = "fichero_entrada.txt") : fichero_entrada_{fichero_entrada} {}

  void AnalizarPrograma();

  void VolcarResultados(std::string fichero_salida = "fichero_salida.txt") const;

 private:
  std::string fichero_entrada_;
  std::vector<Bucle> almacen_bucles_;
  int cantidad_bucles_while_ = 0;
  int cantidad_bucles_for_ = 0;
  std::vector<Comentario> almacen_comentarios_;
  std::vector<Variable> almacen_variables_;
  int cantidad_enteros_ = 0;
  int cantidad_doubles_ = 0;  

  bool main_presente_ = false;
  bool hay_comentario_inicial_ = false;

  bool estado_comentario_multilinea_ = false;
  void CompletarComentarioMultilinea(std::string texto_objetivo, int numero_linea);

  void AnalizarComentarios(std::string texto_objetivo, int numero_linea);
  void AnalizarBucles(std::string texto_objetivo, int numero_linea);
  void AnalizarVariables(std::string texto_objetivo, int numero_linea);
  void DetectarMain(std::string texto_objetivo);
};