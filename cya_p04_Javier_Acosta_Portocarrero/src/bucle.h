// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo bucle.h: fichero de declaración.
// Contiene la declaración de la clase Bucle, la cual almacena la información
// de los bucles encontrados en un programa.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include <iostream>

class Bucle {
 public:
  Bucle(std::string tipo = "unknown", int linea = 0) : linea_{linea}, tipo_{tipo} {}

  friend std::ostream& operator<<(std::ostream& out, const Bucle& bucle_a_mostrar);
  
 private:
  int linea_;
  std::string tipo_;
};