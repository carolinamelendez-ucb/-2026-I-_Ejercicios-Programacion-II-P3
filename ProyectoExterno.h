#pragma once
#include "Proyecto.h"

class ProyectoExterno : public Proyecto {
private:
    float costoPorHora;
    float horas;

public:
    ProyectoExterno(string cod, string nombre, float costoH, float h)
        : Proyecto(cod, nombre) {
        costoPorHora = costoH;
        horas = h;
    }

    float calcularCosto() override {
        return costoPorHora * horas;
    }

    void mostrarInformacion() override {
        cout << "Proyecto Externo: " << nombreProyecto
            << " Costo: " << calcularCosto() << endl;
    }
};