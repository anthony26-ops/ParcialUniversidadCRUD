#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

class Alumno {
private:
    int id;
    std::string nombres;
    std::string apellidos;
    std::string carnet;

public:
    Alumno();
    Alumno(std::string nombres, std::string apellidos, std::string carnet);

    int getId();
    std::string getNombres();
    std::string getApellidos();
    std::string getCarnet();

    void setId(int id);
    void setNombres(std::string nombres);
    void setApellidos(std::string apellidos);
    void setCarnet(std::string carnet);
};

#endif