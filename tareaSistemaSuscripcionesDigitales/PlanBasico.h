#pragma once
#include <iostream>
#include <string>
#include "PlanSuscripcion.h"

using namespace std;

class PlanBasico : public PlanSuscripcion {
public:
    float costoFijo;

    PlanBasico() : PlanSuscripcion("Basico") {
        this->costoFijo = 10;
    }

    float calcularCosto() override {
        return costoFijo;
    }

    void mostrarDetalle() override {
        cout << "Plan: Basico" << endl;
        cout << "Costo: " << costoFijo << endl;
    }

    ~PlanBasico() {
    }
};
