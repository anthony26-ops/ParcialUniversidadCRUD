#ifndef CURSODAO_H
#define CURSODAO_H

#include "ConexionBD.h"
#include "Curso.h"

class CursoDAO {
public:
    void insertar(Curso curso);
    void mostrarTodos();
    void actualizar(int id, Curso curso);
    void eliminar(int id);
};

#endif