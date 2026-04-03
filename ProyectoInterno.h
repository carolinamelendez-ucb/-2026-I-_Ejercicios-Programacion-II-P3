#pragma once
#include "Proyecto.h"

class ProyectoInterno : public Proyecto {
private:
    float costoFijo;

public:
    ProyectoInterno(string cod, string nombre, float costo)
        : Proyecto(cod, nombre) {
        costoFijo = costo;
    }

    float calcularCosto() override {
        return costoFijo;
    }

    void mostrarInformacion() override {
        cout << "Proyecto Interno: " << nombreProyecto
            << " Costo: " << costoFijo << endl;
    }
};