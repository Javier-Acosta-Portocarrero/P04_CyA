// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo comentario.cc: fichero de definicion.
// Contiene la definicion de la clase Comentario, la cual almacena la información
// de los comentarios encontrados en un programa.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include "comentario.h"

/**
  * @brief Sobrecarga del operador de salida para la clase Comentario que imprime toda
  * la informacion del mismo, la linea en la que fue encontrado, el comentario en si..
  *
  * @param out Flujo de salida.
  * @param bucle_a_mostrar Objeto Comentario a imprimir.
  * @return out El flujo de salida modificado.
  */

std::ostream& operator<<(std::ostream& out, const Comentario& comentario_a_mostrar) {
  if (comentario_a_mostrar.linea_final_ != 0) {
    out << "[LINE " << comentario_a_mostrar.linea_comienzo_ << '-' << comentario_a_mostrar.linea_final_ << "] " << comentario_a_mostrar.comentario_;
  } else {
     out << "[LINE " << comentario_a_mostrar.linea_comienzo_ << "] " << comentario_a_mostrar.comentario_;
  }
  return out;
}

/**
  * @brief Metodo de la clase Comentario cuyo objetivo es concatenar el contenido del
  *        objeto comentario con una string adicional.
  *
  * @param comentario_a_concatenar Cadena que se concatenara con el comentario.
  */

void Comentario::ConcatenarComentario(std::string comentario_a_concatenar) {
  comentario_ += comentario_a_concatenar;
}