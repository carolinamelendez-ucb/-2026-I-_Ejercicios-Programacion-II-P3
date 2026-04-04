#pragma once
#include "Pago.h"

class PagoDescuento : public Pago {

public:

    PagoDescuento(float monto) : Pago(monto) {}

    float procesar() override {
        return monto * 0.9;
    }

    void mostrar() override {
        float descuento = monto * 0.10;
        cout << "Monto original: " << monto << endl;
        cout << "Descuento (10%): " << descuento << endl;
        cout << "Total pagado: " << monto - descuento << endl;
    }
};
