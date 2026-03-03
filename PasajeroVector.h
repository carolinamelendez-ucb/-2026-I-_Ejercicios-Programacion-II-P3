#pragma once
#include <iostream>
#include <string>

using namespace std;

class PasajeroVector
{
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;

public:
	PasajeroVector(int tamanio)
	{
		this->pasajeros = new Pasajero * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}

	void agregar(Pasajero* nuevoPasajero)
	{
		pasajeros[indice] = nuevoPasajero;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			pasajeros[i]->mostrar();
		}
	}
	

	void mostrarAsiento()
	{
		for (int i = 0; i < indice; i++)
		{
			if (pasajeros[i]->getNumeroAsiento() == 0)
			{
				pasajeros[i]->mostrar();
			}
		}

	}

};

