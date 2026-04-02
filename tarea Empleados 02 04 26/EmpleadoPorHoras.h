#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;

public:
    EmpleadoPorHoras(int ci, string nombre, int salarioBase, int horas)
        : Empleado(ci, nombre, salarioBase) {
        this->horasTrabajadas = horas;
    }

    float calcularSalario() override {
        return salarioBase * horasTrabajadas;
    }

    virtual void mostrarInformacion() override {
        cout << "Empleado Por Horas - CI: " << ci << ", Nombre: " << nombre
            << ", Horas: " << horasTrabajadas << ", Salario: " << calcularSalario() << endl;
    }
};
