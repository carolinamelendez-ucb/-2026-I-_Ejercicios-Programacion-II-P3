#pragma once
#include <iostream>
#include <string>
#include "Equipo.h"

using namespace std;

class EquiposVector
{
private:
	Equipo** equipos;
	int tamanio;
	int cantidad;

public:
	EquiposVector(int tamanio)
	{
		this->equipos = new Equipo * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}

	void agregar(Equipo* nuevoEquipo)
	{
		equipos[cantidad] = nuevoEquipo;
		cantidad++;
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			equipos[i]->mostrar();
		}
	}


	
	



};

