#pragma once
#include <iostream>
#include <string>
#include "VectorEmpleados.h"

class Empresa {
private:
	VectorEmpleados* listaDe_Empleados;
	
public:
	Empresa(int tamanioEmpleados) {
		listaDe_Empleados = new VectorEmpleados(tamanioEmpleados);
	}

	void registrarEmpleado(Empleado* nvoEmpleado) {
		Empleado* empleadoCI = listaDe_Empleados->buscarCIempleado(nvoEmpleado->getCi());

		if (empleadoCI == nullptr) {
			listaDe_Empleados->agregar(nvoEmpleado);
		}
		else {
			cout << "Ya existe un empleado con CI" << endl;
		}
	}

	void mostrar() {
		listaDe_Empleados->mostrar();
	}

	void mostrarSalario() {
		listaDe_Empleados->mostrarSueldo();
	}


};