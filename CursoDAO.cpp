#include "CursoDAO.h"
#include <iostream>

using namespace std;

void CursoDAO::insertar(Curso curso) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("INSERT INTO cursos (nombre, codigo) VALUES (?, ?)")
               .bind(curso.getNombre(), curso.getCodigo())
               .execute();

        cout << "Curso insertado correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void CursoDAO::mostrarTodos() {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        mysqlx::SqlResult result = session.sql(
            "SELECT id, nombre, codigo FROM cursos"
        ).execute();

        for (mysqlx::Row row : result) {
            cout << "ID: " << row[0] << endl;
            cout << "Nombre: " << row[1] << endl;
            cout << "Codigo: " << row[2] << endl;
            cout << "------------------------" << endl;
        }

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void CursoDAO::actualizar(int id, Curso curso) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("UPDATE cursos SET nombre = ?, codigo = ? WHERE id = ?")
               .bind(curso.getNombre(), curso.getCodigo(), id)
               .execute();

        cout << "Curso actualizado correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void CursoDAO::eliminar(int id) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("DELETE FROM cursos WHERE id = ?")
               .bind(id)
               .execute();

        cout << "Curso eliminado correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}