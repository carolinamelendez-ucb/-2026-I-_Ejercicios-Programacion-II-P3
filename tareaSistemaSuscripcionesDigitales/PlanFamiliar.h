#pragma once
#include <iostream>
#include <string>
#include "PlanSuscripcion.h"

using namespace std;

class PlanFamiliar : public PlanSuscripcion {
public:
    float costoBase;
    int maxUsuarios;
    int usuariosAdicionales;
    float costoPorExtra;

    PlanFamiliar(int usuariosTotales) : PlanSuscripcion("Familiar") {
        this->costoBase = 30;
        this->maxUsuarios = 5;
        this->costoPorExtra = 5;

        if (usuariosTotales > maxUsuarios) {
            this->usuariosAdicionales = usuariosTotales - maxUsuarios;
        }
        else {
            this->usuariosAdicionales = 0;
        }
    }

    float calcularCosto() override {
        return costoBase + (usuariosAdicionales * costoPorExtra);
    }

    void mostrarDetalle() override {
        cout << "Plan: Familiar" << endl;
        cout << "Costo base: " << costoBase << endl;
        if (usuariosAdicionales > 0) {
            cout << "Usuarios adicionales: " << usuariosAdicionales << endl;
            cout << "Costo adicional: " << usuariosAdicionales * costoPorExtra << endl;
        }
        cout << "Total: " << calcularCosto() << endl;
    }

    ~PlanFamiliar() {
    }
};

