#pragma once
#include <iostream>
#include <string>
#include "MetodoPago.h"

using namespace std;

class PagoSinComision : public MetodoPago {
public:
    float procesarPago(float monto) override {
        return monto;
    }

    void mostrarDetalle(float monto) override {
        cout << "Monto original: " << monto << endl;
        cout << "Total pagado: " << monto << endl;
    }

    bool esValido(float monto) override {
        if (monto <= 0) {
            cout << "Error: monto invalido" << endl;
            return false;
        }
        return true;
    }

    ~PagoSinComision() {
    }
};
