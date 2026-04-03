#pragma once
#include "Empleado.h"

class EmpleadoPorHoras : public Empleado {
private:
    float horasTrabajadas;
    float pagoPorHora;

public:
    EmpleadoPorHoras(string ci, string nombre, float horas, float pago)
        : Empleado(ci, nombre) {
        horasTrabajadas = horas;
        pagoPorHora = pago;
    }

    float calcularSalario() override {
        return horasTrabajadas * pagoPorHora;
    }

    void mostrarInformacion() override {
        cout << "Empleado Horas: " << nombreCompleto
            << " CI: " << cedulaIdentidad
            << " Salario: " << calcularSalario() << endl;
    }
};