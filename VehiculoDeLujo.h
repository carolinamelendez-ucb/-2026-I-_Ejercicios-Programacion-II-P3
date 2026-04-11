#pragma once
#include <iostream>
#include <string>
#include "Vehiculo.h"
using namespace std;
class VehiculoDeLujo : public Vehiculo {
private:
	double recargo;
public:
	VehiculoDeLujo(string placa) : Vehiculo(placa, 100)
	{
		this->recargo = 1.2;
	}
	double calcularCosto(int dias) override {
		return costoBase * recargo * dias;
	}
};