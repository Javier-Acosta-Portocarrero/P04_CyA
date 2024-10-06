// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo analizador_programa.h: fichero de cabecera.
// Contiene la declaración de la clase AnalizadorPrograma, la cual se encarga
// de analizar todo el contenido de un programa para volcar los resultados en otro fichero.
// Referencias: Hace uso de todas las demás clases de este programa.
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

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