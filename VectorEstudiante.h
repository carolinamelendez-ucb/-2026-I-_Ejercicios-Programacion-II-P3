#pragma once
#include "EstudianteException.h"

class VectorEstudiante
{
private:
	int tamanio;
	int cantidad;
	Estudiante** lista;
public:
	VectorEstudiante(int tamanio)
	{
		this->lista = new Estudiante * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}

	Estudiante* BuscarPorCi(string ciBuscado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (ciBuscado == lista[i]->getCi())
			{
				return lista[i];
			}
		}
		return nullptr;
	}

	void agregar(Estudiante* nuevoEstudiante)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoEstudiante;
			cantidad++;
		}
	}
	~VectorEstudiante()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}


};