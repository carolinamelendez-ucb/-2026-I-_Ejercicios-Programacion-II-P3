#pragma once
#include <iostream>
#include <string>
#include "Socios.h"

using namespace std;

class SociosVector
{
private:
	Socio** socios;
	int tamanio;
	int cantidad;

public:
	SociosVector(int tamanio)
	{
		this->socios = new Socio * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Socio* nuevoSocio)
	{
		socios[cantidad] = nuevoSocio;
		cantidad++;

	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			socios[i]->mostrar();
		}
	}
	

};

