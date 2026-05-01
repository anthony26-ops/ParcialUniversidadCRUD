#include "ConexionBD.h"

ConexionBD::ConexionBD() {
    host = "localhost";
    puerto = 33060;
    usuario = "root";
    password = "12345678";
    baseDatos = "universidad";
}

mysqlx::Session ConexionBD::conectar() {
    return mysqlx::Session(
        host,
        puerto,
        usuario,
        password,
        baseDatos
    );
}