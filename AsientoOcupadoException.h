#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class AsientoOcupadoException : public exception {
private:
    string mensaje;
public:
    AsientoOcupadoException() {
        mensaje = "El asiento ya esta ocupado";
    }

    char const* what() const {
        return mensaje.c_str();
    }
};