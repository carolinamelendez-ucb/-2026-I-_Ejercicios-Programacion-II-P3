#pragma once
#include "Transporte.h"

class TransporteTerrestre : public Transporte {
public:
    TransporteTerrestre(string placa) : Transporte(placa) {}

    float calcularCosto(float distancia) override {
        float costo = distancia * 0.5;

        if (distancia > 100) {
            costo = costo * (1 + 0.10);
        }

        return costo;
    }
};