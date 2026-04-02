#pragma once
#include "Empleado.h"

class EmpleadoTiempoCompleto : public Empleado {

private:
    float salarioBase;
    float bono;

public:

    EmpleadoTiempoCompleto(const string& nombre, const string& ci, float salarioBase, float bono)
        : Empleado(nombre, ci), salarioBase(salarioBase), bono(bono) {
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Tipo: Tiempo Completo" << endl;
        cout << "Salario Base: " << salarioBase << endl;
        cout << "Bono: " << bono << endl;
    }

    float calcularSalario() override {
        return salarioBase + bono;
    }
};
