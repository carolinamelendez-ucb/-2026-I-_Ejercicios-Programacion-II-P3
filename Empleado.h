#pragma once
#include <iostream>
#include <string>

using namespace std;

class Empleado {

protected:
    string nombre;
    string ci;

public:

    Empleado(const string& nombre, const string& ci)
        : nombre(nombre), ci(ci) {
    }

    string getCi() { return ci; }

    virtual void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
    }

    virtual float calcularSalario() = 0;
};
