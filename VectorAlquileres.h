#pragma once
#include "Alquiler.h"

class VectorAlquileres
{
private:
	int indice; int tamanio;
	Alquiler** alquileres;

public:
	VectorAlquileres(int tamanio)
	{
		this->indice = 0;
		this->tamanio = tamanio;
		this->alquileres = new Alquiler * [tamanio];
	}


	void agregar(Alquiler* nuevoAlquiler)
	{
		if (indice < tamanio)
		{
			alquileres[indice] = nuevoAlquiler;
			indice++;
		}
	}

	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			alquileres[i]->mostrar();
			cout << endl;
		}
	}
};