#pragma once
#include <iostream>
#include <string>
#include "Socio.h"
using namespace std;

class VectorSocio
{
private:
	Socio** socios;
	int tamanio;
	int indice;
public:
	VectorSocio(int tamanio)
	{
		this->socios = new Socio * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Socio* nuevoSocio)
	{
		socios[indice] = nuevoSocio;
		indice++;
	}
	void ordenarPorNombre()
	{
		for (int i = 0; i < indice - 1; i++)
		{
			for (int j = i + 1; j < indice; j++)
			{
				if (socios[i]->getNombre() > socios[j]->getNombre())
				{
					Socio* aux = socios[i];
					socios[i] = socios[j];
					socios[j] = aux;
				}
			}
		}
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			socios[i]->mostrar();
		}
	}
};