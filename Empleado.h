#pragma once
#include <iostream>
#include <string>

using namespace std;

class Empleado{
protected:
	int ci;
	string nombre;
	int salarioBase;

public:
	Empleado(int ci, const string& nombre, int salarioBase)
		: ci(ci), nombre(nombre), salarioBase(salarioBase)
	{
	}

	int getCi() {
		return ci;
	}

	void Mostrar() {
		cout << "CI: "<<ci << endl;
		cout << "Nombre: "<<nombre << endl;
		cout << "Salario Base: "<<salarioBase << endl;
	}

	virtual double calcularSaladio() = 0;
	virtual void mostrarInformacion() = 0;
};