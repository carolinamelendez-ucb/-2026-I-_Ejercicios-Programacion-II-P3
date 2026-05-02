#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class CodigoEspacioDuplicadoException : public exception {
private:
    string mensaje;
public:
    CodigoEspacioDuplicadoException() {
        mensaje = "Codigo esta duplicado";
    }
    char const* what() const {
        return mensaje.c_str();
    }
};