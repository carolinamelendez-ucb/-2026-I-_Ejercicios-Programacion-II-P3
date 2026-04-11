#pragma once
#include <iostream>
#include <string>
#include "Vehiculo.h"
using namespace std;
class VehiculoEconomico : public Vehiculo {
private:
	double recargo;
public:
	VehiculoEconomico(string placa) : Vehiculo(placa, 40)
	{
		this->recargo = 1.2;
	}
	double calcularCosto(int dias) override {
		return costoBase * dias;
	}
};