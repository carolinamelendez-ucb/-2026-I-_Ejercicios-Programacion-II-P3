#pragma once
#include <iostream>
#include <string>

using namespace std;

class Empleado
{
protected:
	string nombre;
	int ci;
	float salarioBase;
public:

	Empleado(string nombre, int ci, float salarioBase)
		: nombre(nombre), ci(ci), salarioBase(salarioBase)
	{}

	virtual float calcularSalario() = 0;
	virtual void  mostrarInformacion() = 0;
	int getCi()
	{
		return ci;
	}

};