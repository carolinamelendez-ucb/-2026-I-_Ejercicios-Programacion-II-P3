#pragma once
#include<iostream>
#include<string>
#include"Empleado.h"
using namespace std;
class EmpleadoTiempoCompleto: public Empleado {
private:
	int cantidadDias;
	float pagoDia;
public:
	EmpleadoTiempoCompleto(string nombre, int ci, float pagoDia, int cantidadDias)
		: Empleado(nombre, ci) {
		this->cantidadDias = cantidadDias;
		this->pagoDia = pagoDia;
	}

	float calcularSalario() {
		return pagoDia* cantidadDias;
	}

	void mostrarInformacion() {

		cout << "Nombre del Empleado a Tiempo Completo: " << nombre << endl;
		cout << "Ci del Empleado a Tiempo Completo: " << ci << endl;
		cout << "Salario: " << calcularSalario() << endl;
	}
};