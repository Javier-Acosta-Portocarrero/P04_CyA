// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo variable.h: fichero de declaración.
// Contiene la declaración de la clase Variable, la cual almacena la información
// de las variables encontradas en un programa.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include <iostream>

class Variable {
 public:
  Variable(std::string tipo = "unknowm", std::string variable = "variable_por_defecto", int linea = 0) : tipo_{tipo}, variable_{variable}, linea_{linea} {}

  friend std::ostream& operator<<(std::ostream& out, const Variable& vairable_a_mostrar);

 private:
  std::string tipo_;
  std::string variable_;
  int linea_;
};