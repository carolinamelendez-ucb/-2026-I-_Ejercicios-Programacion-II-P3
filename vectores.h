#pragma once
#include <iostream>
#include<string>
#include"empleados.h"
#include"proyecto.h"
using namespace std;
class VectorEmpleado {
private:
	Empleado** lista;
	int cantidad;
	int tamanio;
public:
	VectorEmpleado(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->lista = new Empleado * [tamanio];
	}
	void agregar(Empleado* NuevoEmpleado) {
		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getCi() == NuevoEmpleado->getCi()) {
				cout << "Ci duplicado" << endl;
				return;
			}
		}
		if (cantidad < tamanio) {
			lista[cantidad] = NuevoEmpleado;
			cantidad++;
		}
	}
	void mostrar() {
		for (int i = 0; i < cantidad; i++) {
			lista[i]->mostrarInformacion();
		}
	}
	float totalsalarios() {
		float suma = 0;
		for (int i = 0; i < cantidad; i++) {
			suma = suma + lista[i]->calcularSalario();
		}
		return suma;
	}
};
class VectorProyectos {
private:
	Proyecto** lista;
	int cantidad;
	int tamanio;
public:
	VectorProyectos(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->lista = new Proyecto * [tamanio];
	}
	void agregar(Proyecto* NuevoProyecto) {
		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getcodigo() == NuevoProyecto->getcodigo()) {
				cout << "Codigo de proyecto Duplicado" << endl;
				return;
			}
		}
		if (cantidad < tamanio) {
			lista[cantidad] = NuevoProyecto;
			cantidad++;
		}
	}
	void mostrar() {
		for (int i = 0; i < cantidad; i++) {
			lista[i]->mostrar();
		}
	}
	Proyecto* mayorCosto() {
		if (cantidad == 0)return nullptr;
		Proyecto* mayor = lista[0];
		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->CalcularCosto() > mayor->CalcularCosto()) {
				mayor = lista[i];
			}
		}
		return mayor;
	}
};