#include "Alumno.h"

Alumno::Alumno() {
    id = 0;
    nombres = "";
    apellidos = "";
    carnet = "";
}

Alumno::Alumno(std::string nombres, std::string apellidos, std::string carnet) {
    this->id = 0;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->carnet = carnet;
}

int Alumno::getId() {
    return id;
}

std::string Alumno::getNombres() {
    return nombres;
}

std::string Alumno::getApellidos() {
    return apellidos;
}

std::string Alumno::getCarnet() {
    return carnet;
}

void Alumno::setId(int id) {
    this->id = id;
}

void Alumno::setNombres(std::string nombres) {
    this->nombres = nombres;
}

void Alumno::setApellidos(std::string apellidos) {
    this->apellidos = apellidos;
}

void Alumno::setCarnet(std::string carnet) {
    this->carnet = carnet;
}