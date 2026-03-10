#pragma once
#include <iostream>
#include <string>
#include "Equipo.h"
using namespace std;

class VectorEquipo
{
private:
	Equipo** equipos;
	int tamanio;
	int indice;
public:
	VectorEquipo(int tamanio)
	{
		this->equipos = new Equipo * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Equipo* nuevoEquipo)
	{
		equipos[indice] = nuevoEquipo;
		indice++;
	}
	void buscarEquiposDeSocio(string nombre)
	{
		for (int i = 0; i < indice; i++)
		{
			if (equipos[i]->getPiloto()->getNombre() == nombre ||
				equipos[i]->getCopiloto()->getNombre() == nombre)
			{
				equipos[i]->mostrar();
				cout << endl;
			}
		}
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			equipos[i]->mostrar();
		}
	}
};