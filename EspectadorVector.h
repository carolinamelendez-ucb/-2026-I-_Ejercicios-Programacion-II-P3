#pragma once
#include "Espectador.h"

#include <string>
#include <iostream>
using namespace std;

class EspectadorVector
{
private:
	Espectador** espectadores;
	int tamanio;
	int indice;

public:

	EspectadorVector(int tamanio)
	{
		this->indice = 0;
		this->tamanio = tamanio;
		this->espectadores = new Espectador * [tamanio];
	}

	void agregar(Espectador* nuevoEspectador)
	{
		if (indice < tamanio)
		{
			this->espectadores[indice] = nuevoEspectador;
			indice++;
		}
	}

	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			cout << "Lista Espectador ------" << endl;
			this->espectadores[i]->mostrar();
		}
	}
};