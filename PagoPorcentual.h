#pragma once
#include "Pago.h"

class PagoPorcentual : public Pago {

public:

    PagoPorcentual(float monto) : Pago(monto) {}

    float procesar() override {
        return monto * 1.03;
    }

    void mostrar() override {
        float comision = monto * 0.03;
        cout << "Monto original: " << monto << endl;
        cout << "Comision (3%): " << comision << endl;
        cout << "Total pagado: " << monto + comision << endl;
    }
};