#pragma once
#include "Estudiantes.h"
class VectorEstudiantes
{
private:
	int ind;
	int tamanio;
	Estudiantes** lista;
public:
	VectorEstudiantes(int tamanio)
	{
		this->ind = 0;
		this->tamanio = tamanio;
		this->lista = new Estudiantes * [tamanio];
	}
};

