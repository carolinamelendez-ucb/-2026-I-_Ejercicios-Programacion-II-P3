#pragma once
#include <iostream>
#include <string>
#include "PlanSuscripcion.h"

using namespace std;

class Suscripcion {
public:
    PlanSuscripcion* plan;
    float costoFinal;

    Suscripcion(PlanSuscripcion* plan) : plan(plan), costoFinal(0) {
    }

    void procesar() {
        costoFinal = plan->calcularCosto();
    }

    void mostrarDetalle() {
        plan->mostrarDetalle();
    }

    ~Suscripcion() {
        delete plan;
    }
};
