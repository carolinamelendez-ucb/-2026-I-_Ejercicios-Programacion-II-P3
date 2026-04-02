#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

using namespace std;

class ProyectoExterno : public Proyecto {
private:
    float costoConsultoria;
    float costoInfraestructura;
    float impuestos;

public:
    ProyectoExterno(int codigo, string nombre, int duracionMeses, float costoConsultoria, float costoInfraestructura, float impuestos)
        : Proyecto(codigo, nombre, duracionMeses) {
        this->costoConsultoria = costoConsultoria;
        this->costoInfraestructura = costoInfraestructura;
        this->impuestos = impuestos;
    }

    float calcularCosto() override {
        return costoConsultoria + costoInfraestructura + impuestos;
    }

    virtual void mostrarInformacion() override {
        cout << "Proyecto Externo - Codigo: " << codigo << ", Nombre: " << nombre
            << ", Duracion: " << duracionMeses << " meses, Costo Consultoria: " << costoConsultoria
            << ", Costo Infraestructura: " << costoInfraestructura << ", Impuestos: " << impuestos
            << ", Costo Total: " << calcularCosto() << endl;
    }
};

