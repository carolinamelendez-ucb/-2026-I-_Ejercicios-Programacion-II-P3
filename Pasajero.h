#pragma once
#include <iostream>
#include <string>
#include "Asiento.h"
using namespace std;
class Pasajero {
private:
    string ci;
    string nombre;
    string apellido;
    Asiento* asiento;

public:
    Pasajero(string ci, string nombre, string apellido) {
        this->ci = ci;
        this->nombre = nombre;
        this->apellido = apellido;
        this->asiento = nullptr;
    }

    string getCI() { return ci; }

    void asignarAsiento(Asiento* a) {
        asiento = a;
    }

    void mostrar() {
        cout << nombre << " " << apellido << " - CI: " << ci;
        if (asiento != nullptr)
            cout << " - Asiento: " << asiento->getCodigo();
        cout << endl;
    }
};