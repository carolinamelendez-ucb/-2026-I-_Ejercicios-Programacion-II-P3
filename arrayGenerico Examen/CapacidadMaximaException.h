#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class CapacidadMaximaException : public exception {
private:
    string mensaje;

public:
    CapacidadMaximaException() {
        mensaje = "No se puede agregar nuevos elementos el array esta lleno";
    }

    CapacidadMaximaException(int capacidad) {
        mensaje = "Error: Capacidad maxima alcanzada " + to_string(capacidad) + " elementos No se pueden agregar mas elementos";
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }

    ~CapacidadMaximaException() {
        cout << "CapacidadMaximaException destruida" << endl;
    }
};