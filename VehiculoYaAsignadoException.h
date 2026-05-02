#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class VehiculoYaAsignadoException : public exception {
private:
    string mensaje;
public:
    VehiculoYaAsignadoException() {
        mensaje = "El vehiculo ya tiene un espacio asignado.";
    }
    char const* what() const {
        return mensaje.c_str();
    }
};