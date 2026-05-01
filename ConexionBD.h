#ifndef CONEXIONBD_H
#define CONEXIONBD_H

#include <mysqlx/xdevapi.h>
#include <string>

class ConexionBD {
private:
    std::string host;
    int puerto;
    std::string usuario;
    std::string password;
    std::string baseDatos;

public:
    ConexionBD();

    mysqlx::Session conectar();
};

#endif