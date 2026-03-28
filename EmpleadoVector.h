#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"
using namespace std;

class EmpleadoVector {
private:
	Empleado** empleados;
	int indice;
	int tamanio;
public:
	EmpleadoVector(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->empleados = new Empleado * [tamanio];
	}
	void agregar(Empleado* newEmpleado) {
		for (int i = 0; i < indice; i++) {
			if (empleados[i]->getCi() == newEmpleado->getCi()) {
				cout << "El empleado tiene ci duplicado" << endl;
				return;
			}
		}
		if (indice < tamanio) {
			empleados[indice] = newEmpleado;
			indice++;
		}
		else {
			cout << "No hay espacio" << endl;
		}
	}
	void ordenar() {
		for (int i = 0; i < indice - 1; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (empleados[i]->getFunciones() >
					empleados[j]->getFunciones()) {
					swap(empleados[i], empleados[j]);
				}
			}
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			empleados[i]->mostrar();
		}
	}
	Empleado* buscar() {
		Empleado* mejor = nullptr;
		for (int i = 0; i < indice; i++) {
			if (empleados[i]->getDisponibilidad()) {
				if (mejor == nullptr || empleados[i]->getFunciones() < mejor->getFunciones()) {
					mejor = empleados[i];
				}
			}
		}
		return mejor;
	}
};
