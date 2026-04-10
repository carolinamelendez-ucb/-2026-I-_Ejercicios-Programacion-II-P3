#pragma once
#include "Cliente.h"
#include "Vehiculo.h"

class Alquiler
{
private:
	Cliente* cliente;
	Vehiculo* vehiculo;

	int dias; double total;

public:
	Alquiler(Cliente* cliente, Vehiculo* vehiculo, int dias)
	{
		this->cliente = cliente;
		this->vehiculo = vehiculo;
		this->dias = dias;
	}

	double calcularTotal()
	{
		double costo = vehiculo->calcularCosto(dias);
		double descuento = cliente->calcularDescuento();

		return costo - (costo * descuento);
	}

	void mostrar()
	{
		cout << " Ci Cliente " << cliente->getCi() << endl;
		cout << " Vehiculo CI " << vehiculo->getPlaca() << endl;
		cout << "Total : " << calcularTotal() << endl;
	}
};