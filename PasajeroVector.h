#pragma once
#include <iostream>
#include <string>
#include "Pasajero.h"
using namespace std;

class PasajeroVector
{
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	PasajeroVector(int tamanio)//Para el vecto solo se necesitara el tamaño
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
	void mostrarPasajerosSinAsiento()
	{
		for (int i = 0; i < indice; i++)
		{
			if (pasajeros[i]->getNumeroAsiento() == 0)
			{
				pasajeros[i]->mostrar();
			}
		}
	}
	void mostrarPasajerosAsientoImpar()
	{
		for (int i = 0; i < indice; i++)
		{
			if (pasajeros[i]->getNumeroAsiento() % 2 != 0)
			{
				pasajeros[i]->mostrar();
			}
		}
	}
};