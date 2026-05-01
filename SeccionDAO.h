#ifndef SECCIONDAO_H
#define SECCIONDAO_H

#include "ConexionBD.h"
#include "Seccion.h"

class SeccionDAO {
public:
    void insertar(Seccion seccion);
    void mostrarTodos();
    void actualizar(int id, Seccion seccion);
    void eliminar(int id);
};

#endif