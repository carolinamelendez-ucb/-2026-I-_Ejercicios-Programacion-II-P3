#pragma once
#include <iostream>
#include <string>

using namespace std;

class Estudiante {

private:
    int ci;
    string nombre;
    int prestamosActivos;

public:

    Estudiante(int ci, const string& nombre)
        : ci(ci), nombre(nombre), prestamosActivos(0) {
    }

    int getCi() { return ci; }
    int getPrestamos() { return prestamosActivos; }

    bool puedePrestar() { return prestamosActivos < 5; }

    void prestar() { prestamosActivos++; }
    void devolver() { prestamosActivos--; }

    void mostrar() {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Prestamos activos: " << prestamosActivos << endl;
    }
};
