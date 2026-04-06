#pragma once
#include <iostream>
#include <string>
#include "MetodoPago.h"

using namespace std;

class PagoComisionPorcentual : public MetodoPago {
public:
    float comision;

public:
    PagoComisionPorcentual() {
        this->comision = 0.03;
    }

    float procesarPago(float monto) override {
        return monto + (monto * comision);
    }

    void mostrarDetalle(float monto) override {
        float comisionAplicada = monto * comision;
        float total = monto + comisionAplicada;
        cout << "Monto original: " << monto << endl;
        cout << "Comision (3%): " << comisionAplicada << endl;
        cout << "Total pagado: " << total << endl;
    }

    bool esValido(float monto) override {
        return monto > 0;
    }

    ~PagoComisionPorcentual() {
    }
};