#pragma once
#include "Transporte.h"

class Terrestre : public Transporte {

public:

    Terrestre(const string& placa) : Transporte(placa) {}

    float calcularCosto(float distancia) override {
        float costo = distancia * 0.5;
        if (distancia > 100) costo *= 1.10;
        return costo;
    }

    void mostrar() {
        Transporte::mostrar();
        cout << "Tipo: Terrestre" << endl;
    }
};