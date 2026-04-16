#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string ci;
    string nombre;
public:
    Persona(string ci, string nombre) {
        this->ci = ci;
        this->nombre = nombre;
    }

    string getCi() { return ci; }
    string getNombre() { return nombre; }

    virtual void mostrar() {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
    }
};