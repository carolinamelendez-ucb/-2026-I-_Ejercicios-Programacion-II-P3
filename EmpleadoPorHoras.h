#pragma once
#include "Empleado.h"

class EmpleadoPorHoras : public Empleado {

private:
    int horas;
    float pagoHora;

public:

    EmpleadoPorHoras(const string& nombre, const string& ci, int horas, float pagoHora)
        : Empleado(nombre, ci), horas(horas), pagoHora(pagoHora) {
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Tipo: Por Horas" << endl;
        cout << "Horas: " << horas << endl;
        cout << "Pago por hora: " << pagoHora << endl;
    }

    float calcularSalario() override {
        return horas * pagoHora;
    }
};