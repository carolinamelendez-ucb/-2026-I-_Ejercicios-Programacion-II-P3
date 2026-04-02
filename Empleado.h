
#pragma once
#include<iostream>
using namespace std;
class Empleado {
protected:
	string nombre;
	int ci;
public:
	Empleado() = default;

	Empleado(const string& nombre, int ci)
		: nombre(nombre), ci(ci)
	{
	}

	virtual float calcularSalario() = 0;
	virtual void mostrarInformacion() = 0;
		
	int getCi() {
		return ci;
	}
};