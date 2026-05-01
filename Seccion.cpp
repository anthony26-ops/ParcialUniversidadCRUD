#include "Seccion.h"

Seccion::Seccion() {
    id = 0;
    nombre = "";
    jornada = "";
}

Seccion::Seccion(std::string nombre, std::string jornada) {
    this->id = 0;
    this->nombre = nombre;
    this->jornada = jornada;
}

int Seccion::getId() {
    return id;
}

std::string Seccion::getNombre() {
    return nombre;
}

std::string Seccion::getJornada() {
    return jornada;
}

void Seccion::setId(int id) {
    this->id = id;
}

void Seccion::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Seccion::setJornada(std::string jornada) {
    this->jornada = jornada;
}