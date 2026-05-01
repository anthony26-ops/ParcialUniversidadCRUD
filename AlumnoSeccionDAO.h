#ifndef ALUMNOSECCIONDAO_H
#define ALUMNOSECCIONDAO_H

#include "ConexionBD.h"

class AlumnoSeccionDAO {
public:
    void asignarSeccion(int alumnoId, int seccionId);
    void mostrarRelaciones();
    void eliminarRelacion(int id);
};

#endif