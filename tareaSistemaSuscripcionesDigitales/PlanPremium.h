#pragma once
#include <iostream>
#include <string>
#include "PlanSuscripcion.h"

using namespace std;

class PlanPremium : public PlanSuscripcion {
public:
    float costoBase;
    float impuesto;

    PlanPremium() : PlanSuscripcion("Premium") {
        this->costoBase = 20;
        this->impuesto = 0.10;
    }

    float calcularCosto() override {
        return costoBase + (costoBase * impuesto);
    }

    void mostrarDetalle() override {
        float impuestoAplicado = costoBase * impuesto;
        float total = costoBase + impuestoAplicado;
        cout << "Plan: Premium" << endl;
        cout << "Costo base: " << costoBase << endl;
        cout << "Impuesto (10%): " << impuestoAplicado << endl;
        cout << "Total: " << total << endl;
    }

    ~PlanPremium() {
    }
};
