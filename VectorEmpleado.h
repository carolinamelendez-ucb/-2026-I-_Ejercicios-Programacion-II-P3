#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

class VectorEmpleado {
private:
	int tamanio;
	int indice;
	Empleado ** empleados;
public:

	VectorEmpleado(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->empleados = new Empleado * [tamanio];
	}
	void agregar(Empleado * nuevoEmpleado) {
		if (indice< tamanio){
			empleados[indice] = nuevoEmpleado;
			indice++;
		}
		else {
			cout << "ya no se pueden agregar mas empleado, se alcanzo el limite!" << endl;
		}

		
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			empleados[i]->mostrarInformacion();
		}
	}
	Empleado* buscarEmpleado(Empleado* existeEmpleado) {
		for (int i = 0; i < indice; i++) {
			if (empleados[i]->getCi() == existeEmpleado->getCi()) {
				return empleados[i];
			}
		}
		return nullptr;
	}

	float totalSalarios() {
		float total = 0;

		for (int i = 0; i < indice; i++) {
		total=total+empleados[i]->calcularSalario();
		}
		return total;
	}

~VectorEmpleado() {
	for (int i = 0; i < indice; i++) {
		delete empleados[i];
	}
	delete[]empleados;
	}
};