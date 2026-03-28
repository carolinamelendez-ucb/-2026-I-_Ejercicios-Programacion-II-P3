#pragma once
#include <iostream>
#include <string>

using namespace std;

class Empleado {

private:
    string nombre;
    int ci;
    int funcionesAtendidas;
    bool libre;

public:

    Empleado(const string& nombre, int ci)
        : nombre(nombre), ci(ci), funcionesAtendidas(0), libre(true) {
    }

    int getCi() { return ci; }
    int getFunciones() { return funcionesAtendidas; }
    bool estaLibre() { return libre; }

    void ocupar() { libre = false; }
    void liberar() { libre = true; }
    void incrementarFunciones() { funcionesAtendidas++; }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Funciones atendidas: " << funcionesAtendidas << endl;
        cout << "Estado: " << (libre ? "Libre" : "Ocupado") << endl;
    }
};