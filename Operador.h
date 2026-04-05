#pragma once
#include "Transporte.h"

class Operador {
private:
    string ci;
    string nombre;
    Transporte* transporteAsignado;
    float distancia;

public:
    Operador(string ci, string nombre) {
        this->ci = ci;
        this->nombre = nombre;
        this->transporteAsignado = nullptr;
        this->distancia = 0;
    }

    string getCi() {
        return ci;
    }

    void asignarTransporte(Transporte* transporte, float distancia) {
        this->transporteAsignado = transporte;
        this->distancia = distancia;
    }

    float calcularCosto() {
        if (transporteAsignado != nullptr)
            return transporteAsignado->calcularCosto(distancia);

        return 0;
    }

    void mostrar() {
        cout << "Operador: " << nombre << endl;
        cout << "CI: " << ci << endl;

        if (transporteAsignado != nullptr) {
            transporteAsignado->mostrar();
            cout << "Distancia: " << distancia << endl;
            cout << "Costo: " << calcularCosto() << endl;
        }
    }
};