#pragma once
#include "LibroException.h"

class VectorLibro
{
private:
	int tamanio;
	int cantidad;
	Libro** lista;
public:
	VectorLibro(int tamanio)
	{
		this->lista = new Libro * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Libro* nuevoLibro)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoLibro;
			cantidad++;
		}
	}
	~VectorLibro()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
	Libro* BuscarPorCodigo(string codigoBuscado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (codigoBuscado == lista[i]->getCodigo())
			{
				return lista[i];
			}
		}
		return nullptr;
	}

};

