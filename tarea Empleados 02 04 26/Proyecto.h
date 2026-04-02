#pragma once
#include <iostream>
#include <string>

using namespace std;

class Proyecto {
protected:
    int codigo;
    string nombre;
    int duracionMeses;

public:
    Proyecto(int codigo, const string& nombre, int duracionMeses)
        : codigo(codigo), nombre(nombre), duracionMeses(duracionMeses) {
    }

    int getCodigo() {
        return codigo;
    }

    string getNombre() {
        return nombre;
    }

    virtual float calcularCosto() = 0;
    virtual void mostrarInformacion() = 0;
};

