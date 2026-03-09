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
		string nombrePiloto = nuevoEquipo->getPiloto().getNombre();
		string nombreCopiloto = nuevoEquipo->getCopiloto().getNombre();
		if (nombrePiloto != nombreCopiloto)
		{
			equipos[cantidad] = nuevoEquipo;
			cantidad++;
		}
		else
		{
			cout << "El piloto y copiloto tienen el mismo nombre no se puede agregar a un equipo" << endl;
		}
		

	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			equipos[i]->mostrar();
		}
	}


	
	



};

