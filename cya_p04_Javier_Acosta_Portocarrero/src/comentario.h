// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo comentario.h: fichero de declaración.
// Contiene la declaración de la clase Comentario, la cual almacena la información
// de los comentarios encontrados en un programa.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include <iostream>

class Comentario {
 public:
  Comentario(std::string comentario, int linea_comienzo = 0, int linea_final = 0) : comentario_{comentario}, linea_comienzo_{linea_comienzo}, linea_final_{linea_final} {}

  friend std::ostream& operator<<(std::ostream& out, const Comentario& comentario_a_mostrar);
  void ConcatenarComentario(std::string comentario_a_concatenar);

  void set_linea_final(int linea_final) { linea_final_ = linea_final;}
  int get_linea_comienzo() const { return linea_comienzo_;}
  int get_linea_final() const { return linea_final_;}
  std::string get_comentario() const { return comentario_;}

 private:
  std::string comentario_;
  int linea_comienzo_;
  int linea_final_;
};