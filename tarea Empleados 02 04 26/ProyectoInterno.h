#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

using namespace std;

class ProyectoInterno : public Proyecto {
private:
    float costoRecursos;
    float costoPersonal;

public:
    ProyectoInterno(int codigo, string nombre, int duracionMeses, float costoRecursos, float costoPersonal)
        : Proyecto(codigo, nombre, duracionMeses) {
        this->costoRecursos = costoRecursos;
        this->costoPersonal = costoPersonal;
    }

    float calcularCosto() override {
        return costoRecursos + costoPersonal;
    }

    virtual void mostrarInformacion() override {
        cout << "Proyecto Interno - Codigo: " << codigo << ", Nombre: " << nombre
            << ", Duracion: " << duracionMeses << " meses, Costo Recursos: " << costoRecursos
            << ", Costo Personal: " << costoPersonal << ", Costo Total: " << calcularCosto() << endl;
    }
};
