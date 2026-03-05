#pragma once
#include <iostream>
#include <string>

using namespace std;

class Socio {
private:
    string nombre;
    int ci;
    int telefono;

public:
    Socio(string nombre, int ci, int telefono) {
        this->nombre = nombre;
        this->ci = ci;
        this->telefono = telefono;
    }

    string getNombre() { return nombre; }
    int getCi() { return ci; }
    int getTelefono() { return telefono; }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Telefono: " << telefono << endl;
    }
};