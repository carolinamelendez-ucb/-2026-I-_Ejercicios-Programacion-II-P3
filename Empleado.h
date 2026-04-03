#pragma once
#include <iostream>
using namespace std;

class Empleado {
protected:
    string cedulaIdentidad;
    string nombreCompleto;

public:
    Empleado(string ci, string nombre) {
        cedulaIdentidad = ci;
        nombreCompleto = nombre;
    }

    string getCi() { return cedulaIdentidad; }

    virtual float calcularSalario() = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Empleado() {}
};