#ifndef ALUMNODAO_H
#define ALUMNODAO_H

#include "ConexionBD.h"
#include "Alumno.h"

class AlumnoDAO {
public:
    void insertar(Alumno alumno);
    void mostrarTodos();
    void actualizar(int id, Alumno alumno);
    void eliminar(int id);
};

#endif