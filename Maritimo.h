#pragma once
#include "Transporte.h"

class Maritimo : public Transporte {

public:

    Maritimo(const string& placa) : Transporte(placa) {}

    float calcularCosto(float distancia) override {
        float costo = distancia * 1.2;
        if (distancia > 500) costo += 50;
        return costo;
    }

    void mostrar() {
        Transporte::mostrar();
        cout << "Tipo: Maritimo" << endl;
    }
};
