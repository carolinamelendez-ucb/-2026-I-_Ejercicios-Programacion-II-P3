#pragma once
#include "Proyecto.h"

class ProyectoInterno : public Proyecto {

private:
    float costoFijo;
    float mantenimiento;

public:

    ProyectoInterno(const string& codigo, const string& nombre, float costoFijo, float mantenimiento)
        : Proyecto(codigo, nombre), costoFijo(costoFijo), mantenimiento(mantenimiento) {
    }

    void mostrar() {
        Proyecto::mostrar();
        cout << "Tipo: Interno" << endl;
        cout << "Costo fijo: " << costoFijo << endl;
        cout << "Mantenimiento: " << mantenimiento << endl;
    }

    float calcularCosto() override {
        return costoFijo + mantenimiento;
    }
};
