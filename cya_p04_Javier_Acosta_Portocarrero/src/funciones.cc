// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo funciones.cc: fichero de definición
// Contiene la definición de todas las funciones externas
// a las demas clases usadas por el programa, abajo
// se encuentran mas detalles sobre estas.
// Referencias: 
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include "funciones.h"
#include <iostream>

/*
 * @brief Esta función muestra un mensaje de error cuando el usuario no proporciona
 * la entrada correcta a través de la línea de comandos. Además, indica como obtener
 * ayuda sobre el uso del programa.
 *
 * @return No devuelve ningún valor.
 */

void MostrarErrorDeEntrada() {
  std::cout << "Modo de empleo: ./cya_p04_regex program_entrada.txt ficherosalida.txt" << std::endl 
            << "Pruebe  ./cya_p04_regex --help para mas informacion" << std::endl;;
}

/*
 * @brief Esta función muestra un mensaje de ayuda que describe que parametros se deben 
 * poner para la ejecución del programa y el significado de los distintos opcode.
 *
 * @return No devuelve ningún valor.
 */

void MostrarMensajeDeAyuda() {
  std::cout << "Por linea de comandos se debe incluir el nombre del ejecutable seguido por el nombre del"
            <<  " programa de entrada y del fichero de salida en este orden." << std::endl;
}