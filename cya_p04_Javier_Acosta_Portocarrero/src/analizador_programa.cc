// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 06/10/2024
// Archivo analizador_programa.cc: fichero de definicion.
// Contiene la definicion de la clase AnalizadorPrograma, la cual se encarga
// de analizar todo el contenido de un programa para volcar los resultados en otro fichero.
// Referencias: Hace uso de todas las demás clases de este programa.
// Enlaces de interes
//
// Historial de revisiones
// 06/10/2024 - Creacion (primera version) del codigo

#include "analizador_programa.h"

 /**
   * @brief Analiza el contenido de un programa fuente, línea por línea.
   * Identifica la presencia de "main", comentarios, bucles y variables.
   */

void AnalizadorPrograma::AnalizarPrograma() {
  std::ifstream flujo_fichero_entrada(fichero_entrada_);
  if (!flujo_fichero_entrada.is_open()) {
    std::cerr << "No se ha podido abrir el fichero de entrada." << std::endl;
  } else {
    int numero_linea = 1;
    std::string linea;
    while (std::getline(flujo_fichero_entrada, linea)) {
      if (!estado_comentario_multilinea_) {
        DetectarMain(linea);
        AnalizarComentarios(linea, numero_linea);
        AnalizarBucles(linea, numero_linea);
        AnalizarVariables(linea, numero_linea);
      } else {
        CompletarComentarioMultilinea(linea, numero_linea);
      }
      numero_linea++;
    }
    flujo_fichero_entrada.close();
  }
}

/**
  * @brief Vuelca los resultados del análisis del programa en un archivo de salida.
  * Muestra el nombre del programa, las variables, bucles, si el "main" está presente,
  * y los comentarios encontrados.
  * 
  * @param fichero_salida Nombre del archivo de salida donde se escribirán los resultados.
  */
 
void AnalizadorPrograma::VolcarResultados(std::string fichero_salida) const {
  std::ofstream flujo_fichero_salida(fichero_salida);
  flujo_fichero_salida << "PROGRAM: " << fichero_entrada_ << std::endl;

  if (hay_comentario_inicial_) {
    flujo_fichero_salida << "DESCRIPTION:" << std::endl << almacen_comentarios_[0].get_comentario() << std::endl << std::endl;
  }

  if (almacen_variables_.size() > 0) {
    flujo_fichero_salida << "VARIABLES:"  << std::endl;
    for (Variable variable_aux : almacen_variables_) {
      flujo_fichero_salida << variable_aux << std::endl;
    }
    flujo_fichero_salida << std::endl;
  }
  if (almacen_bucles_.size() > 0) {
    flujo_fichero_salida << "STATEMENTS:" << std::endl;
    for (Bucle bucle_aux : almacen_bucles_) {
      flujo_fichero_salida << bucle_aux << std::endl;
    }
    flujo_fichero_salida << std::endl;
  }

  flujo_fichero_salida << "MAIN :" << std::endl;
  if (main_presente_) {
    flujo_fichero_salida << "True" << std::endl << std::endl;
  } else {
    flujo_fichero_salida << "False" << std::endl << std::endl;
  }

  if (almacen_comentarios_.size() > 0) {
    flujo_fichero_salida << "COMMENTS:" << std::endl;
    if (hay_comentario_inicial_) {
      flujo_fichero_salida << "[Line " << almacen_comentarios_[0].get_linea_comienzo(); 
      if (almacen_comentarios_[0].get_linea_final() != 0) {
        flujo_fichero_salida << '-' << almacen_comentarios_[0].get_linea_final();
      }
      flujo_fichero_salida << "] DESCRIPTION" << std::endl;
      for (size_t i{1}; i < almacen_comentarios_.size(); i++) {
        flujo_fichero_salida << almacen_comentarios_[i] << std::endl;
      }
    } else {
      for (size_t i{0}; i < almacen_comentarios_.size(); i++) {
        flujo_fichero_salida << almacen_comentarios_[i] << std::endl;
      }
    }
  }
}

/**
  * @brief Detecta la presencia de la función "main" en el programa.
  * Utiliza una expresión regular para buscarlo.
  * 
  * @param texto_objetivo Línea del programa que se está analizando.
  */

void AnalizadorPrograma::DetectarMain(std::string texto_objetivo) {
  std::regex expresion_regular_main("^int\\smain\\s*\\(.*\\)\\s\\{");
  std::smatch match;
  if (std::regex_search(texto_objetivo, match, expresion_regular_main)) {
    main_presente_ = true;
  }
}

/**
  * @brief Analiza los comentarios del programa a analizar y los almacena.
  * Detecta tanto comentarios de una sola línea como comentarios multilínea.
  * 
  * @param texto_objetivo Línea del programa que se está analizando.
  * @param numero_linea Número de la línea que se está procesando.
  */

void AnalizadorPrograma::AnalizarComentarios(std::string texto_objetivo, int numero_linea) {
  std::regex expresion_regular_comentario_una_linea("//.*"), expresion_regular_comentario_multilinea("/\\*.*");
  std::smatch match;
  if (numero_linea == 1) {
    if (regex_search(texto_objetivo, match, expresion_regular_comentario_multilinea)) {
      hay_comentario_inicial_ = true;
      estado_comentario_multilinea_ = true;
      almacen_comentarios_.emplace_back(Comentario(match[0].str(), numero_linea));
    } else if(regex_search(texto_objetivo, match, expresion_regular_comentario_una_linea)) {
      hay_comentario_inicial_ = true;
      almacen_comentarios_.emplace_back(Comentario(match[0].str(), numero_linea));
    }
  } else {
    if (regex_search(texto_objetivo, match, expresion_regular_comentario_multilinea)) {
      estado_comentario_multilinea_ = true;
      almacen_comentarios_.emplace_back(Comentario(match[0].str(), numero_linea));
    } else if(regex_search(texto_objetivo, match, expresion_regular_comentario_una_linea)) {
      almacen_comentarios_.emplace_back(Comentario(match[0].str(), numero_linea));
    }
  }
}

/**
  * @brief Analiza si una línea contiene bucles "for" o "while".
  * Almacena el bucle encontrado y actualiza los contadores correspondientes.
  * 
  * @param texto_objetivo Línea del programa que se está analizando.
  * @param numero_linea Número de la línea que se está procesando.
  */

void AnalizadorPrograma::AnalizarBucles(std::string texto_objetivo, int numero_linea) {
  std::regex expresion_regular_bucle("^\\s*(for|while)\\s*\\(.*\\)\\s*\\{");
  std::smatch match;
  if (std::regex_search(texto_objetivo, match, expresion_regular_bucle)) {
    almacen_bucles_.emplace_back(Bucle(match[1].str(), numero_linea));
    if (match[1].str() == "for") {
      cantidad_bucles_for_++;
    } else if (match[1].str() == "while") {
      cantidad_bucles_while_++;
    }
  }
}

/**
  * @brief Analiza si una línea contiene la declaración de variables "int" o "double".
  * Almacena las variables encontradas y actualiza los contadores de cada tipo.
  * 
  * @param texto_objetivo Línea del programa que se está analizando.
  * @param numero_linea Número de la línea que se está procesando.
  */

void AnalizadorPrograma::AnalizarVariables(std::string texto_objetivo, int numero_linea) {
  std::regex expresion_regular_variable("^\\s*(int|double)\\s*(\\w+)(\\s*=\\s*[^;]+)?\\s*;");
  std::smatch match;
  if (std::regex_search(texto_objetivo, match, expresion_regular_variable)) {
    almacen_variables_.emplace_back(Variable(match[1].str(), match[2].str() + ((match.size() > 3) ? match[3].str() : ""), numero_linea));
    if (match[1].str() == "int") {
      cantidad_enteros_++;
    } else if (match[1].str() == "double"){
      cantidad_doubles_++;
    }
  }
}

/**
  * @brief Completa el análisis de comentarios multilínea cuando se detecta
  * que una línea forma parte de un comentario iniciado previamente.
  * 
  * @param texto_objetivo Línea del programa que se está analizando.
  * @param numero_linea Número de la línea que se está procesando.
  */

void AnalizadorPrograma::CompletarComentarioMultilinea(std::string texto_objetivo, int numero_linea) {
  std::regex expresion_regular_comentario_multilinea_fin("^\\s*\\*/\\s*$");
  std::smatch match;
  if (std::regex_search(texto_objetivo, match, expresion_regular_comentario_multilinea_fin)) {
    almacen_comentarios_[almacen_comentarios_.size() - 1].ConcatenarComentario("\n" + match[0].str());
    almacen_comentarios_[almacen_comentarios_.size() - 1].set_linea_final(numero_linea);
    estado_comentario_multilinea_ = false;
  } else {
    almacen_comentarios_[almacen_comentarios_.size() - 1].ConcatenarComentario("\n" + texto_objetivo);
  }
}