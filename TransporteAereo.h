#pragma once
#include "Transporte.h"

class TransporteAereo : public Transporte {
public:
    TransporteAereo(string placa) : Transporte(placa) {}

    float calcularCosto(float distancia) override {
        float costo = distancia * 2.0;

        if (distancia > 1000) {
            costo = costo * (1 - 0.15);
        }

        return costo;
    }
};