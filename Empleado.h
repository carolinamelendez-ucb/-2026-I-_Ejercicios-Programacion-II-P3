#pragma once
#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
	string nombre;
	int ci;
	int cantFunciones;
	bool estado;
public:
	Empleado(string nombre, int ci) {
		this->nombre = nombre;
		this->ci = ci;
		this->cantFunciones = 0;
		this->estado = true;
	}
	void ocupado() {
		this->estado = false;
	}
	void liberar() {
		this->estado = true;
	}
	int getCi() {
		return ci;
	}
	int getFunciones() {
		return cantFunciones;
	}
	bool getDisponibilidad() {
		return estado;
	}
	void incrementar() {
		cantFunciones++;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << " | CI: " << ci << " | Funciones: " << cantFunciones << " | Estado: ";
		if (estado == true) {
			cout << "Libre";
		}
		else {
			cout << "Ocupado";
		}
		cout << endl;
	}
};
