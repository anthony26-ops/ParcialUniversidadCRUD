cmake_minimum_required(VERSION 3.20)
project(Parcial2CRUD)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(mysql-concpp_DIR "/usr/local/mysql-connector-c++-9.7.0")

find_package(mysql-concpp REQUIRED)

add_executable(Parcial2CRUD
        main.cpp
        ConexionBD.h
        ConexionBD.cpp
        Alumno.h
        Alumno.cpp
        AlumnoDAO.h
        AlumnoDAO.cpp
        Curso.cpp
        Curso.h
        CursoDAO.cpp
        CursoDAO.h
        Seccion.cpp
        Seccion.h
        SeccionDAO.cpp
        SeccionDAO.h
        AlumnoCursoDAO.cpp
        AlumnoCursoDAO.h
        AlumnoSeccionDAO.cpp
        AlumnoSeccionDAO.h
        Menus.cpp
        Menus.h
)

target_link_libraries(Parcial2CRUD mysql::concpp)

set_target_properties(Parcial2CRUD PROPERTIES
        BUILD_RPATH "/usr/local/mysql-connector-c++-9.7.0/lib64"
)