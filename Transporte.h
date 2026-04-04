#pragma once
#include <iostream>
#include <string>

using namespace std;

class Transporte
{
protected:
	int placa;
public:

	Transporte(int placa)
		: placa(placa)
	{}

	virtual float calcularCosto(float distancia) = 0;
	virtual void mostrarInfo() = 0;
	int getPlaca()
	{
		return placa;
	}
};