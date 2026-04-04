#pragma once
#include "Transporte.h"

class Aereo : public Transporte {

public:

    Aereo(const string& placa) : Transporte(placa) {}

    float calcularCosto(float distancia) override {
        float costo = distancia * 2.0;
        if (distancia > 1000) costo *= 0.85;
        return costo;
    }

    void mostrar() {
        Transporte::mostrar();
        cout << "Tipo: Aereo" << endl;
    }
};