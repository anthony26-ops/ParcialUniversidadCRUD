#include "SeccionDAO.h"
#include <iostream>

using namespace std;

void SeccionDAO::insertar(Seccion seccion) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("INSERT INTO secciones (nombre, jornada) VALUES (?, ?)")
               .bind(seccion.getNombre(), seccion.getJornada())
               .execute();

        cout << "Seccion insertada correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void SeccionDAO::mostrarTodos() {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        mysqlx::SqlResult result = session.sql(
            "SELECT id, nombre, jornada FROM secciones"
        ).execute();

        for (mysqlx::Row row : result) {
            cout << "ID: " << row[0] << endl;
            cout << "Nombre: " << row[1] << endl;
            cout << "Jornada: " << row[2] << endl;
            cout << "------------------------" << endl;
        }

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void SeccionDAO::actualizar(int id, Seccion seccion) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("UPDATE secciones SET nombre = ?, jornada = ? WHERE id = ?")
               .bind(seccion.getNombre(), seccion.getJornada(), id)
               .execute();

        cout << "Seccion actualizada correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}

void SeccionDAO::eliminar(int id) {
    try {
        ConexionBD conexion;
        mysqlx::Session session = conexion.conectar();

        session.sql("DELETE FROM secciones WHERE id = ?")
               .bind(id)
               .execute();

        cout << "Seccion eliminada correctamente." << endl;

    } catch (const mysqlx::Error& err) {
        cerr << "Error MySQL: " << err.what() << endl;
    }
}