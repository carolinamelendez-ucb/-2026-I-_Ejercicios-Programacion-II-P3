#pragma once
#include "Transporte.h"

class Operador {

private:
    string nombre;
    string ci;
    float distancia;
    Transporte* transporte;

public:

    Operador(const string& nombre, const string& ci)
        : nombre(nombre), ci(ci), distancia(0), transporte(nullptr) {
    }

    string getCi() { return ci; }

    void asignarTransporte(Transporte* nuevoTransporte, float distancia) {
        this->transporte = nuevoTransporte;
        this->distancia = distancia;
    }

    float calcularCosto() {
        if (transporte == nullptr) return 0;
        return transporte->calcularCosto(distancia);
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Distancia: " << distancia << endl;

        if (transporte != nullptr) {
            transporte->mostrar();
            cout << "Costo: " << calcularCosto() << endl;
        }
        else {
            cout << "Sin transporte asignado" << endl;
        }
    }
};
