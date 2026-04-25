#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class PasajeroNoExisteException : public exception {
private:
    string mensaje;
public:
    PasajeroNoExisteException() {
        mensaje = "El pasajero no existe";
    }

    char const* what() const {
        return mensaje.c_str();
    }
};
