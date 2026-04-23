#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class LibroNoEncontradoException : public exception {
private:
    string mensaje;

public:
    LibroNoEncontradoException() {
        mensaje = "[LibroNoEncontradoException] No existe el libro en la biblioteca.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class EstudianteNoEncontradoException : public exception {
private:
    string mensaje;

public:
    EstudianteNoEncontradoException() {
        mensaje = "[EstudianteNoEncontradoException] No existe el estudiante en la biblioteca.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class LibroYaPrestadoException : public exception {
private:
    string mensaje;

public:
    LibroYaPrestadoException() {
        mensaje = "[LibroYaPrestadoException] El libro ya esta prestado actualmente.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class LibroEnReparacionException : public exception {
private:
    string mensaje;

public:
    LibroEnReparacionException() {
        mensaje = "[LibroEnReparacionException] El libro esta en reparacion y no puede ser prestado.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};

class EstudianteYaTieneLibroException : public exception {
private:
    string mensaje;

public:
    EstudianteYaTieneLibroException() {
        mensaje = "[EstudianteYaTieneLibroException] El estudiante ya tiene un libro prestado.";
    }

    char const* what() const noexcept override {
        return mensaje.c_str();
    }
};
