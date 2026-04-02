#pragma once
#include "Proyecto.h"

class ProyectoExterno : public Proyecto {

private:
    float costoBase;
    float porcentajeExtra;

public:

    ProyectoExterno(const string& codigo, const string& nombre, float costoBase, float porcentajeExtra)
        : Proyecto(codigo, nombre), costoBase(costoBase), porcentajeExtra(porcentajeExtra) {
    }

    void mostrar() {
        Proyecto::mostrar();
        cout << "Tipo: Externo" << endl;
        cout << "Costo base: " << costoBase << endl;
        cout << "Porcentaje extra: " << porcentajeExtra << endl;
    }

    float calcularCosto() override {
        return costoBase + (costoBase * porcentajeExtra);
    }
};
