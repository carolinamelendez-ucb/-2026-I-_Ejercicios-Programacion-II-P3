#pragma once
#include <string>
#include <iostream>

using namespace std;

#include "Vehiculo.h"

class VehiculoEconomico : public Vehiculo
{
public:
	VehiculoEconomico(string placa) : Vehiculo(placa, 40)
	{

	}

	double calcularCosto(int dias) override
	{
		return costoBase * dias;

	}

};