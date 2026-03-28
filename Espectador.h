#pragma once
#include <iostream>
#include <string>

using namespace std;

class Espectador {

private:
    string nombre;
    string telefono;

public:

    Espectador(const string& nombre, const string& telefono)
        : nombre(nombre), telefono(telefono) {
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
    }
};