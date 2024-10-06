#include "bucle.h"

std::ostream& operator<<(std::ostream& out, const Bucle& bucle_a_mostrar) {
  out << "[LINE " << bucle_a_mostrar.linea_ << "] LOOP: " << bucle_a_mostrar.tipo_;
  return out;
}
