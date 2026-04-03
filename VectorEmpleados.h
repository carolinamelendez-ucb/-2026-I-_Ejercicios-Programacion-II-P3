#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"
using namespace std;

class VectorEmpleados {
private:
	int tamanio;
	int cantidad;
	Empleado** listaEmpleados;
public:
	VectorEmpleados(int tam) {
		this->tamanio = tam;
		this->cantidad = 0;
		this->listaEmpleados = new Empleado * [tam];
	}

	void agregar(Empleado* nvoEmpleado) {
		if (cantidad<tamanio) {
			listaEmpleados[cantidad] = nvoEmpleado;
			cantidad++;
		}
		else {
			cout << "No se pueden agregar mas empleados" << endl;
		}
	}

	Empleado* buscarCIempleado(int ciBuscado){
		for (int i = 0;i < cantidad;i++) {
			if (listaEmpleados[i]->getCi() == ciBuscado) {
				return listaEmpleados[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			listaEmpleados[i]->Mostrar();
		}
	}

	void mostrarSueldo() {
		for (int i = 0;i < cantidad;i++) {
			listaEmpleados[i]->calcularSaladio();
		}
	}

};


