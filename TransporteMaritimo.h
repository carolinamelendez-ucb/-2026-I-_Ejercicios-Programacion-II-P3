#pragma once
#include "Transporte.h"

class TransporteMaritimo : public Transporte {
public:
    TransporteMaritimo(string placa) : Transporte(placa) {}

    float calcularCosto(float distancia) override {
        float costo = distancia * 1.2;

        if (distancia > 500) {
            costo += 50;
        }

        return costo;
    }
};