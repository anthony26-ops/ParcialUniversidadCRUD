#include "Menus.h"

#include <iostream>
#include <string>
#include <limits>

#include "AlumnoDAO.h"
#include "CursoDAO.h"
#include "SeccionDAO.h"
#include "AlumnoCursoDAO.h"
#include "AlumnoSeccionDAO.h"

using namespace std;

// Funcion para limpiar el buffer cuando mezclamos cin con getline
void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funcion para pausar la consola
void pausar() {
    cout << "\nPresione ENTER para continuar...";
    limpiarBuffer();
}

// ========================
// MENU PRINCIPAL
// ========================

void menuPrincipal() {
    int opcion;

    do {
        cout << "\n========== MENU PRINCIPAL ==========" << endl;
        cout << "1. Alumnos" << endl;
        cout << "2. Cursos" << endl;
        cout << "3. Secciones" << endl;
        cout << "4. Alumnos - Cursos" << endl;
        cout << "5. Alumnos - Seccion" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuAlumnos();
                break;

            case 2:
                menuCursos();
                break;

            case 3:
                menuSecciones();
                break;

            case 4:
                menuAlumnosCursos();
                break;

            case 5:
                menuAlumnosSeccion();
                break;

            case 6:
                cout << "\nSaliendo del programa..." << endl;
                exit(0);

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
}

// ========================
// MENU ALUMNOS
// ========================

void menuAlumnos() {
    AlumnoDAO alumnoDAO;
    int opcion;

    do {
        cout << "\n========== MENU ALUMNOS ==========" << endl;
        cout << "1. Insertar alumno" << endl;
        cout << "2. Mostrar alumnos" << endl;
        cout << "3. Actualizar alumno" << endl;
        cout << "4. Eliminar alumno" << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombres;
                string apellidos;
                string carnet;

                limpiarBuffer();

                cout << "\nIngrese nombres: ";
                getline(cin, nombres);

                cout << "Ingrese apellidos: ";
                getline(cin, apellidos);

                cout << "Ingrese carnet: ";
                getline(cin, carnet);

                Alumno alumno(nombres, apellidos, carnet);
                alumnoDAO.insertar(alumno);
                break;
            }

            case 2:
                cout << "\n========== LISTA DE ALUMNOS ==========" << endl;
                alumnoDAO.mostrarTodos();
                break;

            case 3: {
                int id;
                string nombres;
                string apellidos;
                string carnet;

                cout << "\nIngrese el ID del alumno a actualizar: ";
                cin >> id;

                limpiarBuffer();

                cout << "Ingrese nuevos nombres: ";
                getline(cin, nombres);

                cout << "Ingrese nuevos apellidos: ";
                getline(cin, apellidos);

                cout << "Ingrese nuevo carnet: ";
                getline(cin, carnet);

                Alumno alumno(nombres, apellidos, carnet);
                alumnoDAO.actualizar(id, alumno);

                break;
            }

            case 4: {
                int id;

                cout << "\nIngrese el ID del alumno a eliminar: ";
                cin >> id;

                alumnoDAO.eliminar(id);

                break;
            }

            case 0:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
}

// ========================
// MENU CURSOS
// ========================

void menuCursos() {
    CursoDAO cursoDAO;
    int opcion;

    do {
        cout << "\n========== MENU CURSOS ==========" << endl;
        cout << "1. Insertar curso" << endl;
        cout << "2. Mostrar cursos" << endl;
        cout << "3. Actualizar curso" << endl;
        cout << "4. Eliminar curso" << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                string codigo;

                limpiarBuffer();

                cout << "\nIngrese nombre del curso: ";
                getline(cin, nombre);

                cout << "Ingrese codigo del curso: ";
                getline(cin, codigo);

                Curso curso(nombre, codigo);
                cursoDAO.insertar(curso);

                break;
            }

            case 2:
                cout << "\n========== LISTA DE CURSOS ==========" << endl;
                cursoDAO.mostrarTodos();
                break;

            case 3: {
                int id;
                string nombre;
                string codigo;

                cout << "\nIngrese el ID del curso a actualizar: ";
                cin >> id;

                limpiarBuffer();

                cout << "Ingrese nuevo nombre del curso: ";
                getline(cin, nombre);

                cout << "Ingrese nuevo codigo del curso: ";
                getline(cin, codigo);

                Curso curso(nombre, codigo);
                cursoDAO.actualizar(id, curso);

                break;
            }

            case 4: {
                int id;

                cout << "\nIngrese el ID del curso a eliminar: ";
                cin >> id;

                cursoDAO.eliminar(id);

                break;
            }

            case 0:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
}

// ========================
// MENU SECCIONES
// ========================

void menuSecciones() {
    SeccionDAO seccionDAO;
    int opcion;

    do {
        cout << "\n========== MENU SECCIONES ==========" << endl;
        cout << "1. Insertar seccion" << endl;
        cout << "2. Mostrar secciones" << endl;
        cout << "3. Actualizar seccion" << endl;
        cout << "4. Eliminar seccion" << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                string jornada;

                limpiarBuffer();

                cout << "\nIngrese nombre de la seccion: ";
                getline(cin, nombre);

                cout << "Ingrese jornada: ";
                getline(cin, jornada);

                Seccion seccion(nombre, jornada);
                seccionDAO.insertar(seccion);

                break;
            }

            case 2:
                cout << "\n========== LISTA DE SECCIONES ==========" << endl;
                seccionDAO.mostrarTodos();
                break;

            case 3: {
                int id;
                string nombre;
                string jornada;

                cout << "\nIngrese el ID de la seccion a actualizar: ";
                cin >> id;

                limpiarBuffer();

                cout << "Ingrese nuevo nombre de la seccion: ";
                getline(cin, nombre);

                cout << "Ingrese nueva jornada: ";
                getline(cin, jornada);

                Seccion seccion(nombre, jornada);
                seccionDAO.actualizar(id, seccion);

                break;
            }

            case 4: {
                int id;

                cout << "\nIngrese el ID de la seccion a eliminar: ";
                cin >> id;

                seccionDAO.eliminar(id);

                break;
            }

            case 0:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
}

// ========================
// MENU ALUMNOS - CURSOS
// ========================

void menuAlumnosCursos() {
    AlumnoCursoDAO alumnoCursoDAO;
    AlumnoDAO alumnoDAO;
    CursoDAO cursoDAO;

    int opcion;

    do {
        cout << "\n========== MENU ALUMNOS - CURSOS ==========" << endl;
        cout << "1. Asignar curso a alumno" << endl;
        cout << "2. Mostrar asignaciones de cursos" << endl;
        cout << "3. Eliminar asignacion de curso" << endl;
        cout << "4. Mostrar alumnos" << endl;
        cout << "5. Mostrar cursos" << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int alumnoId;
                int cursoId;

                cout << "\n========== ALUMNOS DISPONIBLES ==========" << endl;
                alumnoDAO.mostrarTodos();

                cout << "\n========== CURSOS DISPONIBLES ==========" << endl;
                cursoDAO.mostrarTodos();

                cout << "\nIngrese ID del alumno: ";
                cin >> alumnoId;

                cout << "Ingrese ID del curso: ";
                cin >> cursoId;

                alumnoCursoDAO.asignarCurso(alumnoId, cursoId);

                break;
            }

            case 2:
                cout << "\n========== ASIGNACIONES ALUMNOS - CURSOS ==========" << endl;
                alumnoCursoDAO.mostrarRelaciones();
                break;

            case 3: {
                int id;

                cout << "\n========== ASIGNACIONES ACTUALES ==========" << endl;
                alumnoCursoDAO.mostrarRelaciones();

                cout << "\nIngrese el ID de la relacion a eliminar: ";
                cin >> id;

                alumnoCursoDAO.eliminarRelacion(id);

                break;
            }

            case 4:
                cout << "\n========== LISTA DE ALUMNOS ==========" << endl;
                alumnoDAO.mostrarTodos();
                break;

            case 5:
                cout << "\n========== LISTA DE CURSOS ==========" << endl;
                cursoDAO.mostrarTodos();
                break;

            case 0:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
}

// ========================
// MENU ALUMNOS - SECCIONES
// ========================

void menuAlumnosSeccion() {
    AlumnoSeccionDAO alumnoSeccionDAO;
    AlumnoDAO alumnoDAO;
    SeccionDAO seccionDAO;

    int opcion;

    do {
        cout << "\n========== MENU ALUMNOS - SECCIONES ==========" << endl;
        cout << "1. Asignar seccion a alumno" << endl;
        cout << "2. Mostrar asignaciones de secciones" << endl;
        cout << "3. Eliminar asignacion de seccion" << endl;
        cout << "4. Mostrar alumnos" << endl;
        cout << "5. Mostrar secciones" << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int alumnoId;
                int seccionId;

                cout << "\n========== ALUMNOS DISPONIBLES ==========" << endl;
                alumnoDAO.mostrarTodos();

                cout << "\n========== SECCIONES DISPONIBLES ==========" << endl;
                seccionDAO.mostrarTodos();

                cout << "\nIngrese ID del alumno: ";
                cin >> alumnoId;

                cout << "Ingrese ID de la seccion: ";
                cin >> seccionId;

                alumnoSeccionDAO.asignarSeccion(alumnoId, seccionId);

                break;
            }

            case 2:
                cout << "\n========== ASIGNACIONES ALUMNOS - SECCIONES ==========" << endl;
                alumnoSeccionDAO.mostrarRelaciones();
                break;

            case 3: {
                int id;

                cout << "\n========== ASIGNACIONES ACTUALES ==========" << endl;
                alumnoSeccionDAO.mostrarRelaciones();

                cout << "\nIngrese el ID de la relacion a eliminar: ";
                cin >> id;

                alumnoSeccionDAO.eliminarRelacion(id);

                break;
            }

            case 4:
                cout << "\n========== LISTA DE ALUMNOS ==========" << endl;
                alumnoDAO.mostrarTodos();
                break;

            case 5:
                cout << "\n========== LISTA DE SECCIONES ==========" << endl;
                seccionDAO.mostrarTodos();
                break;

            case 0:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
}