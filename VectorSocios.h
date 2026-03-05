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
	Socio* buscarPorNombre(string nombre)
	{
		for (int i = 0; i < indice; i++)
		{
			if (socios[i]->getNombre() == nombre)
			{
				return socios[i];
			}
		}
		return NULL;
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			socios[i]->mostrar();
		}
	}
};