#pragma once
#include <iostream>
#include <string>
using namespace std;
class Empleado {
private:
	string nombre;
	int ci;
	int cantFunciones;
	bool libre;
public:
	Empleado(const string& nombre, int ci)
		: nombre(nombre), ci(ci), cantFunciones(0), libre(true)
	{
	}
	int getCI() {
		return ci;
	}
	int getFunciones() {
		return cantFunciones;
	}
	bool estaLibre() {
		return libre;
	}
	void ocupar() {
		libre = false;
	}
	void liberar() {
		libre = true;
	}
	void incrementoFunciones() {
		cantFunciones++;
	}
	void mostrarEmpleado() {
		cout << "Nombre: " << nombre << endl;
		cout << "CI: " << ci << endl;
		cout << "Funciones atendidas: " << endl;
		cout << "Estado: ";
		if (libre) {
			cout << "Libre" << endl;
		}
		else {
			cout << "Ocupado" << endl;
		}
	}
};