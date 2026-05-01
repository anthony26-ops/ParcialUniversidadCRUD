#ifndef CURSO_H
#define CURSO_H

#include <string>

class Curso {
private:
    int id;
    std::string nombre;
    std::string codigo;

public:
    Curso();
    Curso(std::string nombre, std::string codigo);

    int getId();
    std::string getNombre();
    std::string getCodigo();

    void setId(int id);
    void setNombre(std::string nombre);
    void setCodigo(std::string codigo);
};

#endif