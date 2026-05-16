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
        mensaje = "Error: El codigo del espacio ya existe en el sistema";
    }

    CodigoEspacioDuplicadoException(const string& codigo) {
        mensaje = "Error: El codigo de espacio " + codigo + " ya esta registrado en el sistema";
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }

    ~CodigoEspacioDuplicadoException() {
        cout << "CodigoEspacioDuplicadoException destruida" << endl;
    }
};