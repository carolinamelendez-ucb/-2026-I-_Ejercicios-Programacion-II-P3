#pragma once
#include <iostream>
#include <string>
#include "EmpleadoVector.h"
#include "FuncionVector.h"
using namespace std;

class Sistema {
private:
	EmpleadoVector* empleados;
	FuncionVector* funciones;
public:
	Sistema(int tamanioEmpleados, int tamanioFunciones) {
		this->empleados = new EmpleadoVector (tamanioEmpleados);
		this->funciones = new FuncionVector(tamanioFunciones);
	}
	void mostrarEmpleadosOrdenados() {
		empleados->ordenar();
		empleados->mostrar();
	}
	void registrarEmpleado(string nombre, int ci) {
		Empleado* nuevo = new Empleado(nombre, ci);
		empleados->agregar(nuevo);
	}
	void registrarFuncion(string nombre, int codigo, int maxEspectadores) {
		Empleado* empl = empleados->buscar();
		if (empl != nullptr) {
			empl->ocupado();
			Funcion* nuevaFuncion = new Funcion(nombre, codigo, maxEspectadores, empl);
			funciones->agregar(nuevaFuncion);
		}
		else {
			cout << "No hay empleados libres para asignar la funcion" << endl;
		}
	}
	void finalizar(int codigo) {
		Funcion* f = funciones->buscar(codigo);
		if (f != nullptr) {
			f->finalizar();
			cout << "finalizado" << endl;
		}
	}
};
