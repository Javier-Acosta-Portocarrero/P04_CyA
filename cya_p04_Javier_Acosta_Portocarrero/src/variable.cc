#include "variable.h"

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