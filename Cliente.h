#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente {

private:
    string nombre;
    int telefono;

public:

    Cliente(const string& nombre, int telefono)
        : nombre(nombre), telefono(telefono)
    {
    }

    string getNombre() {
        return nombre;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
    }
};