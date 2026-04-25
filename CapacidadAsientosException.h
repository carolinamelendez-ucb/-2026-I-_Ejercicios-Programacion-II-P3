#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class CapacidadAsientosException : public exception {
private:
    string mensaje;
public:
    CapacidadAsientosException() {
        mensaje = "Se supero la capacidad de asientos";
    }

    char const* what() const {
        return mensaje.c_str();
    }
};
