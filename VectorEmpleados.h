#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"
using namespace std;
class VectorEmpleados {
private:
	Empleado** empleados;
	int indice;
	int tamanio;
public:
	VectorEmpleados(int tamanio) : tamanio(tamanio), indice(0) {
		empleados = new Empleado * [tamanio];
	}
	~VectorEmpleados() {
		for (int i = 0; i < indice; i++) {
			delete empleados[i];
		}
		delete[] empleados;
	}
	void agregar(Empleado* nueEmpleado) {
		if (buscar(nueEmpleado->getCI()) != nullptr) {
			cout << "CI duplicado" << endl;
			delete nueEmpleado;
			return;
		}
		if (indice < tamanio) {
			empleados[indice] = nueEmpleado;
			indice++;
		}
	}
	Empleado* buscar(int ci) {
		for (int i = 0; i < indice; i++) {
			if (empleados[i]->getCI() == ci) {
				return empleados[i];
			}
		}
		return nullptr;
	}
	Empleado* buscarLibreMenosFunciones() {
		Empleado* mejorEmpleado = nullptr;
		for (int i = 0; i < indice; i++) {
			if (empleados[i]->estaLibre()) {
				if (mejorEmpleado == nullptr || empleados[i]->getFunciones() < mejorEmpleado->getFunciones()) {
					mejorEmpleado = empleados[i];
				}
			}
		}
		return mejorEmpleado;
	}
	void ordenarPorFunciones() {
		for (int i = 0; i < indice - 1; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (empleados[i]->getFunciones() > empleados[j]->getFunciones()) {
					Empleado* aux = empleados[i];
					empleados[i] = empleados[j];
					empleados[j] = aux;
				}
			}
		}
	}
	void mostrarVectoresEmpleados() {
		for (int i = 0; i < indice; i++) {
			cout << "Empleado " << i + 1 << endl;
			empleados[i]->mostrarEmpleado();
			cout << endl;
		}
	}
};