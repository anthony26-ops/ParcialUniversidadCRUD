#include "Curso.h"

Curso::Curso() {
    id = 0;
    nombre = "";
    codigo = "";
}

Curso::Curso(std::string nombre, std::string codigo) {
    this->id = 0;
    this->nombre = nombre;
    this->codigo = codigo;
}

int Curso::getId() {
    return id;
}

std::string Curso::getNombre() {
    return nombre;
}

std::string Curso::getCodigo() {
    return codigo;
}

void Curso::setId(int id) {
    this->id = id;
}

void Curso::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Curso::setCodigo(std::string codigo) {
    this->codigo = codigo;
}