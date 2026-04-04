#pragma once
#include "Pago.h"

class PagoValidado : public Pago {

public:

    PagoValidado(float monto) : Pago(monto) {}

    float procesar() override {
        if (monto <= 0) return 0;
        return monto;
    }

    void mostrar() override {
        if (monto <= 0) {
            cout << "Error: monto invalido" << endl;
        }
        else {
            cout << "Pago realizado correctamente" << endl;
            cout << "Monto: " << monto << endl;
        }
    }
};