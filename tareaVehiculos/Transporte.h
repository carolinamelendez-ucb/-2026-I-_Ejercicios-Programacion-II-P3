#pragma once
#include <iostream>
#include <string>

using namespace std;

class Transporte {
public:
    string placa;
    string modelo;
    float tarifaPorKm;

public:
    Transporte(const string& placa, const string& modelo, float tarifaPorKm)
        : placa(placa), modelo(modelo), tarifaPorKm(tarifaPorKm) {
    }

    virtual float calcularCosto(float distancia) = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Transporte() {
    }
};
