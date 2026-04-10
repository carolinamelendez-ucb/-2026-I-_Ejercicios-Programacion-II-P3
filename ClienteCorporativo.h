#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

class ClienteCorporativo : public Cliente
{
private:
	float descuento;
public:
	ClienteCorporativo(int ci, string nombre, int maxHistorial) : Cliente(ci, nombre, maxHistorial)
	{
		this->descuento = 0.15;
	}

	double calcularDescuento() override
	{
		return descuento;
	}
};
