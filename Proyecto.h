#pragma once
#include <iostream>
#include <string>

using namespace std;

class Proyecto {

protected:
    string codigo;
    string nombre;

public:

    Proyecto(const string& codigo, const string& nombre)
        : codigo(codigo), nombre(nombre) {
    }

    string getCodigo() { return codigo; }

    virtual void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
    }

    virtual float calcularCosto() = 0;
};