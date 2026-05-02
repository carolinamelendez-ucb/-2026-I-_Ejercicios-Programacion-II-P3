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
        mensaje = "No se puede aniadir nuevos elementos, el array esta lleno.";
    }
    char const* what() const {
        return mensaje.c_str();
    }
};

