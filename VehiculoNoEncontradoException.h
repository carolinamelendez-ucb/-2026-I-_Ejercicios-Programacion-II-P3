#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class VehiculoNoEncontradoException : public exception {
private:
    string mensaje;
public:
    VehiculoNoEncontradoException() {
        mensaje = "El vehiculo con esa placa no fue encontrado.";
    }
    char const* what() const {
        return mensaje.c_str();
    }
};