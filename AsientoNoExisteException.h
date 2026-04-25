#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class AsientoNoExisteException : public exception {
private:
    string mensaje;
public:
    AsientoNoExisteException() {
        mensaje = "El asiento no existe";
    }

    char const* what() const {
        return mensaje.c_str();
    }
};
