#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class PasajeroDuplicadoException : public exception {
private:
    string mensaje;
public:
    PasajeroDuplicadoException() {
        mensaje = "CI duplicado en el vuelo";
    }

    char const* what() const {
        return mensaje.c_str();
    }
};