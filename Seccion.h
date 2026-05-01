#ifndef SECCION_H
#define SECCION_H

#include <string>

class Seccion {
private:
    int id;
    std::string nombre;
    std::string jornada;

public:
    Seccion();
    Seccion(std::string nombre, std::string jornada);

    int getId();
    std::string getNombre();
    std::string getJornada();

    void setId(int id);
    void setNombre(std::string nombre);
    void setJornada(std::string jornada);
};

#endif