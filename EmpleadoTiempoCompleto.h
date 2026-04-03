#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class EmpleadoTiempoCompleto : public Empleado {
private:
	int horasTrabajadas;

public:
	EmpleadoTiempoCompleto(int ci, string name, int salario, int horas) :
		Empleado(ci, name, salario) {
		this->horasTrabajadas = horas;
	}

	double calcularSaladio() override {
		return salarioBase * horasTrabajadas;
	}

	virtual void mostrarInformacion() override {
		cout << "EmpleadoTiempoCompleto" << endl;
	}
};