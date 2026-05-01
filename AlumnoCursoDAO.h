#ifndef ALUMNOCURSODAO_H
#define ALUMNOCURSODAO_H

#include "ConexionBD.h"

class AlumnoCursoDAO {
public:
    void asignarCurso(int alumnoId, int cursoId);
    void mostrarRelaciones();
    void eliminarRelacion(int id);
};

#endif