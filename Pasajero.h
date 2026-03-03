#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pasajero {
private:
    string nombre;
    int ci;
    int numeroAsiento;

public:
    Pasajero() {
        nombre = "";
        ci = 0;
        numeroAsiento = 0;
    }

    Pasajero(string nombre, int ci) {
        this->nombre = nombre;
        this->ci = ci;
        numeroAsiento = 0;
    }

    void asignarAsiento(int numero) {
        numeroAsiento = numero;
    }

    string getNombre() {
        return nombre;
    }

    int getCi() {
        return ci;
    }

    int getAsiento() {
        return numeroAsiento;
    }

    void mostrar() {
        cout << "Nombre: " << nombre
            << " CI: " << ci
            << " Asiento: " << numeroAsiento << endl;
    }
};