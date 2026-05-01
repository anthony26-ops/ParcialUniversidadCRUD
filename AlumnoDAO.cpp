#include "AlumnoDAO.h"
#include <iostream>

using namespace std;

void AlumnoDAO::insertar(Alumno alumno) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("INSERT INTO alumnos (nombres, apellidos, carnet) VALUES (?, ?, ?)")
               .bind(alumno.getNombres(), alumno.getApellidos(), alumno.getCarnet())
               .execute();

        cout << "Alumno insertado correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoDAO::mostrarTodos() {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        mysqlx::SqlResult result = session.sql(
            "SELECT id, nombres, apellidos, carnet FROM alumnos"
        ).execute();

        for (mysqlx::Row row : result) {
            cout << "ID: " << row[0] << endl;
            cout << "Nombres: " << row[1] << endl;
            cout << "Apellidos: " << row[2] << endl;
            cout << "Carnet: " << row[3] << endl;
            cout << "------------------------" << endl;
        }

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoDAO::actualizar(int id, Alumno alumno) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("UPDATE alumnos SET nombres = ?, apellidos = ?, carnet = ? WHERE id = ?")
               .bind(alumno.getNombres(), alumno.getApellidos(), alumno.getCarnet(), id)
               .execute();

        cout << "Alumno actualizado correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void AlumnoDAO::eliminar(int id) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("DELETE FROM alumnos WHERE id = ?")
               .bind(id)
               .execute();

        cout << "Alumno eliminado correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}