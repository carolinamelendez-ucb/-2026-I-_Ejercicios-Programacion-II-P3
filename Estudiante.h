#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    string ci;

public:
    Estudiante() {}

    Estudiante(string nombre, string ci)
        : nombre(nombre), ci(ci) {
    }

    void mostrar() {
        cout << nombre << " - " << ci << endl;
    }
};
