#pragma once
#include <iostream>
#include <string>
#include "MetodoPago.h"

using namespace std;

class PagoComisionFija : public MetodoPago {
public:
    float comisionFija;

public:
    PagoComisionFija() {
        this->comisionFija = 5;
    }

    float procesarPago(float monto) override {
        return monto + comisionFija;
    }

    void mostrarDetalle(float monto) override {
        cout << "Monto original: " << monto << endl;
        cout << "Comision fija: " << comisionFija << endl;
        cout << "Total pagado: " << monto + comisionFija << endl;
    }

    bool esValido(float monto) override {
        return monto > 0;
    }

    ~PagoComisionFija() {
    }
};