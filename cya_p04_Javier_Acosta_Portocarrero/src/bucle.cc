// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo bucle.cc: fichero de definicion.
// Contiene la definicion de la clase Bucle, la cual almacena la información
// de los bucles encontrados en un programa.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include "bucle.h"

/**
  * @brief Sobrecarga del operador de salida para la clase Bucle que imprime toda
  * la informacion del mismo, la linea en la que fue encontrado, el tipo...
  *
  * @param out Flujo de salida.
  * @param bucle_a_mostrar Objeto bucle a imprimir.
  * @return out El flujo de salida modificado.
  */

std::ostream& operator<<(std::ostream& out, const Bucle& bucle_a_mostrar) {
  out << "[LINE " << bucle_a_mostrar.linea_ << "] LOOP: " << bucle_a_mostrar.tipo_;
  return out;
}
