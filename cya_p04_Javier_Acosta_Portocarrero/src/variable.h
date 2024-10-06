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