#pragma once
#include <iostream>
#include <string>
#include "Vehiculo.h"

class VectorVehiculo
{
private:

	int tamanio;
	int indice;
	Vehiculo** vehiculos;

public:

	VectorVehiculo(int tamanio)
	{
		this->indice = 0;
		this->tamanio = tamanio;
		this->vehiculos = new Vehiculo * [tamanio];
	}
	void agregar(Vehiculo* nuevoVehiculo)
	{
		if (indice < tamanio)
		{
			vehiculos[indice] = nuevoVehiculo;
			indice++;
		}
	}

	Vehiculo* buscar(string placa)
	{
		for (int i = 0; i < indice; i++)
		{
			if (vehiculos[i]->getPlaca() == placa)
			{
				return vehiculos[i];
			}
		}
		return nullptr;
	}

	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			vehiculos[i]->mostrar();
			cout << endl;
		}
	}
	


};