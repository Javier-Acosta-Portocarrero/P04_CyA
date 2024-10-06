#include <iostream>

class Comentario {
 public:
  Comentario(std::string comentario, int linea_comienzo = 0, int linea_final = 0) : comentario_{comentario}, linea_comienzo_{linea_comienzo}, linea_final_{linea_final} {}

  friend std::ostream& operator<<(std::ostream& out, const Comentario& comentario_a_mostrar);
  void ConcatenarComentario(std::string comentario_a_concatenar);

  void set_linea_final(int linea_final) { linea_final_ = linea_final;}
  int get_linea_comienzo() const { return linea_comienzo_;}
  int get_linea_final() const { return linea_final_;}
  std::string get_comentario() const { return comentario_;}

 private:
  std::string comentario_;
  int linea_comienzo_;
  int linea_final_;
};