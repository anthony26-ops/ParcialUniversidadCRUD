# Sistema de Gestión Académica (CRUD en C++)

Este proyecto es una aplicación de consola desarrollada en **C++** que permite gestionar un sistema académico básico mediante operaciones CRUD (Crear, Leer, Actualizar, Eliminar). Implementa el patrón de arquitectura **DAO (Data Access Object)** para interactuar con una base de datos MySQL.

---

## 🛠 Requisitos del Sistema

Para compilar y ejecutar este proyecto, necesitas:

1. **Compilador C++**: Soporte para el estándar C++20.
2. **CMake**: Versión 3.20 o superior.
3. **MySQL Connector/C++**: Versión 9.7.0 instalada (la ruta por defecto en el `CMakeLists.txt` es `/usr/local/mysql-connector-c++-9.7.0`).
4. **Base de Datos MySQL**: Servidor corriendo y configurado para aceptar conexiones según los parámetros en `ConexionBD.cpp`.

---

## 🏗 Arquitectura del Proyecto

El código está estructurado separando la lógica de la base de datos y la representación de los datos, mejorando el mantenimiento y escalabilidad:

### 1. Entidades / Modelos (No-DAO)
Representan los objetos del mundo real y almacenan temporalmente la información en memoria:
- `Alumno.h` / `Alumno.cpp`: Datos como nombres, apellidos y carnet.
- `Curso.h` / `Curso.cpp`: Datos como nombre del curso y código.
- `Seccion.h` / `Seccion.cpp`: Datos como nombre de la sección y jornada.

### 2. Capa de Acceso a Datos (DAO)
Clases dedicadas exclusivamente a conectarse a la base de datos MySQL, ejecutar consultas `SQL` e instanciar/modificar entidades:
- `AlumnoDAO`: CRUD para la tabla de alumnos.
- `CursoDAO`: CRUD para la tabla de cursos.
- `SeccionDAO`: CRUD para la tabla de secciones.
- `AlumnoCursoDAO`: Gestiona las asignaciones (relación N:M) entre alumnos y cursos.
- `AlumnoSeccionDAO`: Gestiona las asignaciones (relación N:M) entre alumnos y secciones.

### 3. Conexión a Base de Datos
- `ConexionBD.h` / `ConexionBD.cpp`: Clase encargada de establecer y devolver la conexión a MySQL usando `mysql::concpp`.

### 4. Interfaz de Usuario
- `Menus.h` / `Menus.cpp`: Contiene la lógica de todos los menús interactivos en la terminal. Recolecta la entrada del usuario y delega las operaciones a los DAOs correspondientes.
- `main.cpp`: Punto de entrada de la aplicación que arranca el `menuPrincipal()`.

---

## 🕹 Guía de Uso Detallada

Al ejecutar el programa, se presentará el **Menú Principal**:

```text
========== MENU PRINCIPAL ==========
1. Alumnos
2. Cursos
3. Secciones
4. Alumnos - Cursos
5. Alumnos - Seccion
6. Salir
```

A continuación se detalla cada submenú:

### 1. Menú Alumnos
Permite gestionar la tabla de estudiantes.
* **Insertar alumno**: Pide *Nombres, Apellidos y Carnet*, crea un objeto `Alumno` y lo manda al `AlumnoDAO` para guardarlo en la BD.
* **Mostrar alumnos**: Obtiene la lista completa desde la BD y la imprime en consola.
* **Actualizar alumno**: Mediante el ID del alumno (obtenido de la opción 2), pide los nuevos datos y sobrescribe el registro en la BD.
* **Eliminar alumno**: Elimina el registro por completo a través de su ID.

### 2. Menú Cursos
Permite gestionar las materias a impartir.
* **Insertar curso**: Solicita el *Nombre y Código* del curso.
* **Mostrar cursos**: Lista los cursos existentes.
* **Actualizar curso**: Mediante el ID, permite cambiar el nombre o el código.
* **Eliminar curso**: Elimina un curso permanentemente por su ID.

### 3. Menú Secciones
Permite gestionar los grupos o jornadas de estudio.
* **Insertar sección**: Solicita el *Nombre* (Ej: "A", "B") y *Jornada* (Ej: "Matutina", "Vespertina").
* **Mostrar secciones**: Lista las secciones registradas.
* **Actualizar sección**: Modifica nombre o jornada usando el ID de la sección.
* **Eliminar sección**: Elimina el registro de la sección por ID.

### 4. Menú Alumnos - Cursos (Asignación)
Maneja las relaciones entre qué alumnos están asignados a qué cursos.
* **Asignar curso a alumno**: Primero muestra los alumnos disponibles y luego los cursos. Te pide ingresar el ID del alumno y el ID del curso para vincularlos en la base de datos.
* **Mostrar asignaciones**: Muestra el historial y los vínculos actuales (Ej: "Juan Pérez está en Programación I").
* **Eliminar asignación**: Elimina el vínculo entre un alumno y un curso utilizando el ID de la relación.
* También cuenta con opciones rápidas para mostrar las listas de Alumnos o Cursos y facilitar la visualización de los IDs.

### 5. Menú Alumnos - Secciones (Asignación)
Similar al menú anterior, maneja en qué sección se encuentra estudiando cada alumno.
* **Asignar sección a alumno**: Vincula el ID de un alumno con el ID de una sección.
* **Mostrar asignaciones**: Muestra todos los alumnos con su respectiva sección.
* **Eliminar asignación**: Rompe la relación entre un alumno y una sección en la base de datos.
* Incluye atajos para ver la lista de alumnos y secciones disponibles.

---

## 🚀 Compilación y Ejecución (CLion o Terminal)

Si utilizas CMake desde la terminal en el directorio del proyecto:

```bash
# Crear directorio de compilación
mkdir build && cd build

# Generar archivos
cmake ..

# Compilar
make

# Ejecutar
./Parcial2CRUD
```

**Nota**: Asegúrate de tener la ruta del conector MySQL (`mysql-concpp_DIR`) configurada correctamente en el archivo `CMakeLists.txt` si tu instalación no está en `/usr/local/mysql-connector-c++-9.7.0`.

### Script de base de datos

El proyecto incluye el archivo `universidad.sql`, que crea la base de datos `universidad` y las tablas requeridas:

- `alumnos`
- `cursos`
- `secciones`
- `alumnos_cursos`
- `alumnos_seccion`

Para cargarlo manualmente:

```bash
mysql -h localhost -P 3306 -u root -p < universidad.sql
```

Si al ejecutar el binario en macOS aparece un error de librerías dinámicas, puede iniciarse así:

```bash
export DYLD_LIBRARY_PATH=/usr/local/mysql-connector-c++-9.7.0/lib64
./Parcial2CRUD
```

---

## ✅ Evidencia de verificación

Verificado el `2026-05-01` contra una instancia local de MySQL.

- La base `universidad` existe y responde correctamente.
- Las tablas `alumnos`, `cursos`, `secciones`, `alumnos_cursos` y `alumnos_seccion` existen.
- El programa logró conectarse a MySQL y listar registros desde los menús de alumnos, cursos y secciones.
- También se verificó el listado de relaciones en `alumnos_cursos` y `alumnos_seccion`.

Datos visibles durante la prueba:

- `alumnos`: 2 registros
- `cursos`: 3 registros
- `secciones`: 2 registros
- `alumnos_cursos`: 1 registro
- `alumnos_seccion`: 1 registro
