#pragma once

#include <iostream>
#include <string>

using namespace std;

class BasicException : public exception {
private:
    string mensaje;

public:
    BasicException(string mensaje) {
        this->mensaje = mensaje;
    }

    virtual char const* what() const noexcept override
    {
        return mensaje.c_str();
    }
};


// ===============================
// CURSOS
// ===============================

class CursoDuplicadoException : public BasicException {
public:
    CursoDuplicadoException() :
        BasicException("El nuevo curso tiene un codigo duplicado") {

    }
};

class CupoInvalidoException : public BasicException {
public:
    CupoInvalidoException() :
        BasicException("La capacidad maxima del curso es menor o igual a 0 o mayor a 30") {

    }
};


// ===============================
// ESTUDIANTES
// ===============================

class EstudianteDuplicadoException : public BasicException {
public:
    EstudianteDuplicadoException() :
        BasicException("El estudiante tiene un CI duplicado") {

    }
};

class EstudianteNoEncontradoException : public BasicException {
public:
    EstudianteNoEncontradoException() :
        BasicException("El estudiante no existe") {

    }
};


// ===============================
// INSCRIPCIONES
// ===============================

class SinCursosDisponiblesException : public BasicException {
public:
    SinCursosDisponiblesException() :
        BasicException("No existen cursos con cupos disponibles en esa modalidad") {

    }
};

class LimiteInscripcionesException : public BasicException {
public:
    LimiteInscripcionesException() :
        BasicException("El estudiante supera el maximo permitido de cursos activos (maximo 3)") {

    }
};

class InscripcionNoEncontradaException : public BasicException {
public:
    InscripcionNoEncontradaException() :
        BasicException("La inscripcion no existe") {

    }
};

class InscripcionYaCanceladaException : public BasicException {
public:
    InscripcionYaCanceladaException() :
        BasicException("La inscripci�n ya fue cancelada (revisar estado)") {

    }
};
