#include "comentario.h"

std::ostream& operator<<(std::ostream& out, const Comentario& comentario_a_mostrar) {
  if (comentario_a_mostrar.linea_final_ != 0) {
    out << "[LINE " << comentario_a_mostrar.linea_comienzo_ << '-' << comentario_a_mostrar.linea_final_ << "] " << comentario_a_mostrar.comentario_;
  } else {
     out << "[LINE " << comentario_a_mostrar.linea_comienzo_ << "] " << comentario_a_mostrar.comentario_;
  }
  return out;
}

void Comentario::ConcatenarComentario(std::string comentario_a_concatenar) {
  comentario_ += comentario_a_concatenar;
}