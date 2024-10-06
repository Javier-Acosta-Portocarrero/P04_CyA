// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo cliente_analizador_programa.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las AnalizadorPrograma, Bucle, Comentario y Variable
// para asi conseguir analizar el contenido de un programa y volcar los resultados en un fichero.
// Referencias: Hace uso de la clase AnalizadorPrograma.
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include <iostream>
#include "analizador_programa.h"

int main(int argc, char *argv[]) {
  AnalizadorPrograma prueba1(argv[1]);
  prueba1.AnalizarPrograma();
  prueba1.VolcarResultados(argv[2]);
  return 0;
}