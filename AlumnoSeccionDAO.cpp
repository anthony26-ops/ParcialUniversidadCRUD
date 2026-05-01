#include "AlumnoSeccionDAO.h"
#include <iostream>

using namespace std;

void AlumnoSeccionDAO::asignarSeccion(int alumnoId, int seccionId) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("INSERT INTO alumnos_seccion (alumno_id, seccion_id) VALUES (?, ?)")
               .bind(alumnoId, seccionId)
               .execute();

        cout << "Seccion asignada al alumno correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoSeccionDAO::mostrarRelaciones() {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        mysqlx::SqlResult result = session.sql(
            "SELECT ase.id, a.nombres, a.apellidos, s.nombre "
            "FROM alumnos_seccion ase "
            "INNER JOIN alumnos a ON ase.alumno_id = a.id "
            "INNER JOIN secciones s ON ase.seccion_id = s.id"
        ).execute();

        for (mysqlx::Row row : result) {
            cout << "ID relacion: " << row[0] << endl;
            cout << "Alumno: " << row[1] << " " << row[2] << endl;
            cout << "Seccion: " << row[3] << endl;
            cout << "------------------------" << endl;
        }

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoSeccionDAO::eliminarRelacion(int id) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("DELETE FROM alumnos_seccion WHERE id = ?")
               .bind(id)
               .execute();

        cout << "Relacion eliminada correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}
