#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

class ClienteBasico : public Cliente
{
public:
	ClienteBasico(int ci, string nombre, int maxHistorial) : Cliente(ci, nombre, maxHistorial)
	{

	}

	double calcularDescuento()
	{
		return 0;
	}
};