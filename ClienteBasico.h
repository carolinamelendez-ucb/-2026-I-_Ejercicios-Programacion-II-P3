#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;
class ClienteBasico : public Cliente {
public:
	ClienteBasico(int ci, string nombre, int maxHistorial) : Cliente(ci, nombre, maxHistorial)
	{

	}
	double calcularDescuento() override {
		return 0;
	}
};