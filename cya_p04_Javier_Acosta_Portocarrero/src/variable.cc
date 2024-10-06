// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo variable.cc: fichero de definicion.
// Contiene la definicion de la clase Variable, la cual almacena la información
// de las variables encontradas en un programa.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo


#include "variable.h"

/**
  * @brief Sobrecarga del operador de salida para la clase Variable que imprime toda
  * la informacion de la misma, la linea en la que fue encontrada, su tipo..
  *
  * @param out Flujo de salida.
  * @param bucle_a_mostrar Objeto Variable a imprimir.
  * @return out El flujo de salida modificado.
  */

std::ostream& operator<<(std::ostream& out, const Variable& variable_a_mostrar) {
  out << "[LINE " << variable_a_mostrar.linea_;
  if (variable_a_mostrar.tipo_ == "int") {
    out << "] INT: ";
  } else {
    out << "] DOUBLE: ";
  }
  out << variable_a_mostrar.variable_;
  return out;
}