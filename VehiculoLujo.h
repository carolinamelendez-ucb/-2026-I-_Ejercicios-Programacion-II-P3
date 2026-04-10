#pragma once
#include <string>
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class VehiculoLujo : public Vehiculo
{
private:
	double recargo;
public:
	VehiculoLujo(string placa) : Vehiculo(placa, 100)
	{
		this->recargo = 1.2; // sumara 
	}

	double calcularCosto(int dias) override
	{
		return (costoBase * dias) * recargo;
	}

};