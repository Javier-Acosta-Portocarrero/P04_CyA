#include <iostream>

class Bucle {
 public:
  Bucle(std::string tipo = "unknown", int linea = 0) : linea_{linea}, tipo_{tipo} {}

  friend std::ostream& operator<<(std::ostream& out, const Bucle& bucle_a_mostrar);
  
 private:
  int linea_;
  std::string tipo_;
};