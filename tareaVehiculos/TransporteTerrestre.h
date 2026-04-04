#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"

using namespace std;

class TransporteTerrestre : public Transporte {
public:
    TransporteTerrestre(const string& placa, const string& modelo)
        : Transporte(placa, modelo, 0.5) {
    }

    float calcularCosto(float distancia) override {
        float recargo = 0.10;
        if (distancia <= 100) {
            recargo = 0.15;
        }
        return distancia * tarifaPorKm * (1 + recargo);
    }

    virtual void mostrarInformacion() override {
        cout << "Transporte Terrestre - Placa: " << placa << ", Modelo: " << modelo
            << ", Tarifa: " << tarifaPorKm << " por km" << endl;
    }

    ~TransporteTerrestre() {
    }
};
