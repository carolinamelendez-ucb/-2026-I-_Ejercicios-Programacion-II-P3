#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"
#include <algorithm>

using namespace std;

class VectorEmpleado {
private:
	int tamanio;
	int indice;
	Empleado** empleados;
public:

	VectorEmpleado() = default;

	VectorEmpleado(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->empleados = new Empleado * [tamanio];
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			empleados[i]->mostrar();
		}
	}
	void agregar(Empleado * nuevoEmpleado ) {
		if (indice < tamanio) {
			empleados[indice] = nuevoEmpleado;
			indice++;
		}
		else {
			cout << "No se puede registrar mas Empleados, error!" << endl;
		}
	}

	bool buscarCiExistente(int ci) {
		for (int i = 0; i < indice; i++) {
			if (empleados[i]->getCi() == ci) {
				return true;
			}
		}
		return false;
	}

	void oredenarEmpleadosCantidadFunciones() {
		sort(empleados, empleados + indice, [](Empleado* a, Empleado* b) {
			return a->getCantidadFuncionesAtendidas() > b->getCantidadFuncionesAtendidas();
			}		
		);
	}
	Empleado * empeladoMenorCantidadLibre() {
		Empleado* auxEmpleado = nullptr;
		for (int i = 0; i < indice; i++) {
			if (auxEmpleado == nullptr || empleados[i]->getCantidadFuncionesAtendidas() < auxEmpleado->getCantidadFuncionesAtendidas()) {
				
				if (empleados[i]->getEstado() == true) {

					auxEmpleado = empleados[i];
				}
			}
		}
		return auxEmpleado;
	}
	~VectorEmpleado() {
		for (int i = 0; i < indice; i++) {
			delete empleados[i];
		}
		delete[]empleados;
	}


};
