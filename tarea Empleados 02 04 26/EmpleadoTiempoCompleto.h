#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class EmpleadoTiempoCompleto : public Empleado {
private:
    int horasTrabajadas;
    float bono;

public:
    EmpleadoTiempoCompleto(int ci, string nombre, int salarioBase, int horas, float bono)
        : Empleado(ci, nombre, salarioBase) {
        this->horasTrabajadas = horas;
        this->bono = bono;
    }

    float calcularSalario() override {
        return (salarioBase * horasTrabajadas) + bono;
    }

    virtual void mostrarInformacion() override {
        cout << "Empleado Tiempo Completo - CI: " << ci << ", Nombre: " << nombre
            << ", Horas: " << horasTrabajadas << ", Bono: " << bono
            << ", Salario: " << calcularSalario() << endl;
    }
};
