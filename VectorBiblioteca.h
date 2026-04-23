#pragma once
#include "LibroException.h"

class VectorBiblioteca
{
private:
	int tamanio;
	int cantidad;
	Libro** lista;
public:
	VectorBiblioteca(int tamanio)
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
	~VectorBiblioteca()

};

