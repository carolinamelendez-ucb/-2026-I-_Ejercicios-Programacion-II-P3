#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"


using namespace std;


class VectorTransportes
{
private:
	Transporte** lista;
	int cantidad;
	int tamanio;
public:
	VectorTransportes(int tamanio)
	{
		this->lista = new Transporte * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Transporte* nuevoTransporte)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoTransporte;
			cantidad++;
		}
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrarInfo();
		}
	}
	Transporte* buscar(int placaDuplicada)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (placaDuplicada == lista[i]->getPlaca())
			{
				return lista[i];
			}
		}
		return nullptr;
	}
	
	~VectorTransportes()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[] lista;
	}
};

