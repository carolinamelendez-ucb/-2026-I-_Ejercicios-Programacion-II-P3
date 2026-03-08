#pragma once
#include <iostream>
#include <string>
using namespace std;

class Socio {
private:
    string nombre;
    int ci;
    string telefono;

public:
    Socio(const string& nombre, int ci, const string& telefono) {
        this->nombre = nombre;
        this->ci = ci;
        this->telefono = telefono;
    }

    ~Socio() {
        cout << "Destructor del socio: " << this->nombre << endl;
    }

    string getNombre() {
        return this->nombre;
    }

    int getCI() {
        return this->ci;
    }

    string getTelefono() {
        return this->telefono;
    }

    void setNombre(const string& nuevoNombre) {
        this->nombre = nuevoNombre;
    }

    void setTelefono(const string& nuevoTelefono) {
        this->telefono = nuevoTelefono;
    }

    void mostrar() {
        cout << "CI: " << this->ci << ", Nombre: " << this->nombre
            << ", Telefono: " << this->telefono << endl;
    }
};
