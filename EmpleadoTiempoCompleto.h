#pragma once
#include "Empleado.h"

class EmpleadoTiempoCompleto : public Empleado {
private:
    float salarioMensual;

public:
    EmpleadoTiempoCompleto(string ci, string nombre, float salario)
        : Empleado(ci, nombre) {
        salarioMensual = salario;
    }

    float calcularSalario() override {
        return salarioMensual;
    }

    void mostrarInformacion() override {
        cout << "Empleado TC: " << nombreCompleto
            << " CI: " << cedulaIdentidad
            << " Salario: " << salarioMensual << endl;
    }
};