#include "AlumnoCursoDAO.h"
#include <iostream>

using namespace std;

void AlumnoCursoDAO::asignarCurso(int alumnoId, int cursoId) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("INSERT INTO alumnos_cursos (alumno_id, curso_id) VALUES (?, ?)")
               .bind(alumnoId, cursoId)
               .execute();

        cout << "Curso asignado al alumno correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoCursoDAO::mostrarRelaciones() {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        mysqlx::SqlResult result = session.sql(
            "SELECT ac.id, a.nombres, a.apellidos, c.nombre "
            "FROM alumnos_cursos ac "
            "INNER JOIN alumnos a ON ac.alumno_id = a.id "
            "INNER JOIN cursos c ON ac.curso_id = c.id"
        ).execute();

        for (mysqlx::Row row : result) {
            cout << "ID relacion: " << row[0] << endl;
            cout << "Alumno: " << row[1] << " " << row[2] << endl;
            cout << "Curso: " << row[3] << endl;
            cout << "------------------------" << endl;
        }

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoCursoDAO::eliminarRelacion(int id) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("DELETE FROM alumnos_cursos WHERE id = ?")
               .bind(id)
               .execute();

        cout << "Relacion eliminada correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}