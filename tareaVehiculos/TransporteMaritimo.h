#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"

using namespace std;

class TransporteMaritimo : public Transporte {
public:
    TransporteMaritimo(const string& placa, const string& modelo)
        : Transporte(placa, modelo, 1.2) {
    }

    float calcularCosto(float distancia) override {
        float recargoFijo = 0;
        if (distancia > 500) {
            recargoFijo = 50;
        }
        return distancia * tarifaPorKm + recargoFijo;
    }

    virtual void mostrarInformacion() override {
        cout << "Transporte Maritimo - Placa: " << placa << ", Modelo: " << modelo
            << ", Tarifa: " << tarifaPorKm << " por km" << endl;
    }

    ~TransporteMaritimo() {
    }
};