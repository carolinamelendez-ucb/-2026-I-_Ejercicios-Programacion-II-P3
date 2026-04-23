#pragma once
#include "Libro.h"
class VectorLibros
{
private:
	int ind;
	int tamanio;
	Libro** lista;
public:
	VectorLibros(int tamanio)
	{
		this->ind = 0;
		this->tamanio = tamanio;
		this->lista = new Libro * [tamanio];
	}
};

