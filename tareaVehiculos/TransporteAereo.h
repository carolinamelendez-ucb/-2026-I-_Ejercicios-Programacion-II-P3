#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"

using namespace std;

class TransporteAereo : public Transporte {
public:
    TransporteAereo(const string& placa, const string& modelo)
        : Transporte(placa, modelo, 2.0) {
    }

    float calcularCosto(float distancia) override {
        float descuento = 0;
        if (distancia > 1000) {
            descuento = 0.15;
        }
        return distancia * tarifaPorKm * (1 - descuento);
    }

    virtual void mostrarInformacion() override {
        cout << "Transporte Aereo - Placa: " << placa << ", Modelo: " << modelo
            << ", Tarifa: " << tarifaPorKm << " por km" << endl;
    }

    ~TransporteAereo() {
    }
};