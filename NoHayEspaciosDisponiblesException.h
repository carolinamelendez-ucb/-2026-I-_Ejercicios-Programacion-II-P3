#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class NoHayEspaciosDisponiblesException : public exception {
private:
    string mensaje;
public:
    NoHayEspaciosDisponiblesException() {
        mensaje = "No hay espacios disponibles en el parqueo.";
    }
    char const* what() const {
        return mensaje.c_str();
    }
};