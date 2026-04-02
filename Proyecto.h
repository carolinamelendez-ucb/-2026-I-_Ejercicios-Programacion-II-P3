#pragma once
#include <iostream>
#include <string>

using namespace std;

class Proyecto
{
protected:
	string nombre;
	int presupuesto;
	int codigo;

public:

	Proyecto(const string& nombre, int presupuesto, int codigo)
		: nombre(nombre), presupuesto(presupuesto), codigo(codigo)
	{}
	virtual float calcularCosto() = 0;
	virtual void mostrarInfo() = 0;
	int getCodigo()
	{
		return codigo;
	}
};