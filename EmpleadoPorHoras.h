#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class EmpleadoPorHoras : public Empleado {

public:
	EmpleadoPorHoras(int ci, string name, int salario) :
		Empleado(ci, name, salario) {

	}

	double calcularSaladio() override {
		return (salarioBase * 100)/7;
	}

	virtual void mostrarInformacion() override {
		cout << "EmpleadoPorHoras" << endl;
	}
};