#pragma once
#include <iostream>
#include <string>

using namespace std;

class PlanSuscripcion {
public:
    string nombre;

    PlanSuscripcion(const string& nombre) : nombre(nombre) {
    }

    virtual float calcularCosto() = 0;
    virtual void mostrarDetalle() = 0;
    virtual ~PlanSuscripcion() {
    }
};

