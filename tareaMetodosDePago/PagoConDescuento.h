#pragma once
#include <iostream>
#include <string>
#include "MetodoPago.h"

using namespace std;

class PagoConDescuento : public MetodoPago {
public:
    float descuento;

public:
    PagoConDescuento() {
        this->descuento = 0.10;
    }

    float procesarPago(float monto) override {
        return monto - (monto * descuento);
    }

    void mostrarDetalle(float monto) override {
        float descuentoAplicado = monto * descuento;
        float total = monto - descuentoAplicado;
        cout << "Monto original: " << monto << endl;
        cout << "Descuento (10%): " << descuentoAplicado << endl;
        cout << "Total pagado: " << total << endl;
    }

    bool esValido(float monto) override {
        return monto > 0;
    }

    ~PagoConDescuento() {
    }
};