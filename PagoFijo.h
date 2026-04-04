#pragma once
#include "Pago.h"

class PagoFijo : public Pago {

public:

    PagoFijo(float monto) : Pago(monto) {}

    float procesar() override {
        return monto + 5;
    }

    void mostrar() override {
        cout << "Monto original: " << monto << endl;
        cout << "Comision fija: 5" << endl;
        cout << "Total pagado: " << monto + 5 << endl;
    }
};
