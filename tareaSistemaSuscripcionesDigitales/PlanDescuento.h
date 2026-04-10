#pragma once
#include <iostream>
#include <string>
#include "PlanSuscripcion.h"

using namespace std;

class PlanDescuento : public PlanSuscripcion {
public:
    float montoOriginal;
    float porcentajeDescuento;

    PlanDescuento(float monto) : PlanSuscripcion("Descuento") {
        this->montoOriginal = monto;
        this->porcentajeDescuento = 0.20;
    }

    float calcularCosto() override {
        return montoOriginal - (montoOriginal * porcentajeDescuento);
    }

    void mostrarDetalle() override {
        float descuentoAplicado = montoOriginal * porcentajeDescuento;
        float total = montoOriginal - descuentoAplicado;
        cout << "Plan: Descuento" << endl;
        cout << "Monto original: " << montoOriginal << endl;
        cout << "Descuento (20%): " << descuentoAplicado << endl;
        cout << "Total: " << total << endl;
    }

    ~PlanDescuento() {
    }
};
