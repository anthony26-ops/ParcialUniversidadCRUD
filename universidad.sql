CREATE DATABASE IF NOT EXISTS universidad;
USE universidad;

CREATE TABLE IF NOT EXISTS alumnos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombres VARCHAR(100) NOT NULL,
    apellidos VARCHAR(100) NOT NULL,
    carnet VARCHAR(30) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS cursos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    codigo VARCHAR(30) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS secciones (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    jornada VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS alumnos_cursos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    alumno_id INT NOT NULL,
    curso_id INT NOT NULL,
    CONSTRAINT fk_alumnos_cursos_alumno
        FOREIGN KEY (alumno_id) REFERENCES alumnos(id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_alumnos_cursos_curso
        FOREIGN KEY (curso_id) REFERENCES cursos(id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT uq_alumnos_cursos UNIQUE (alumno_id, curso_id)
);

CREATE TABLE IF NOT EXISTS alumnos_seccion (
    id INT AUTO_INCREMENT PRIMARY KEY,
    alumno_id INT NOT NULL,
    seccion_id INT NOT NULL,
    CONSTRAINT fk_alumnos_seccion_alumno
        FOREIGN KEY (alumno_id) REFERENCES alumnos(id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_alumnos_seccion_seccion
        FOREIGN KEY (seccion_id) REFERENCES secciones(id)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT uq_alumnos_seccion UNIQUE (alumno_id, seccion_id)
);
