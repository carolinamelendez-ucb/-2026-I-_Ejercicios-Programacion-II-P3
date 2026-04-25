#pragma once
#include <iostream>
#include <string>
#include "Asiento.h"

using namespace std;

class Pasajero {
private:
    int ci;
    string nombre;
    string apellido;
    Asiento* asiento;
public:
    Pasajero(int ci, string nombre, string apellido) {
        this->ci = ci;
        this->nombre = nombre;
        this->apellido = apellido;
        asiento = nullptr;
    }

    int getCi() { return ci; }
    Asiento* getAsiento() { return asiento; }

    void asignarAsiento(Asiento* a) {
        asiento = a;
    }

    void mostrar() {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        if (asiento != nullptr) {
            cout << "Asiento: " << asiento->getCodigo() << endl;
        }
        else {
            cout << "Asiento: No asignado" << endl;
        }
    }
};