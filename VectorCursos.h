#pragma once
#include "Curso.h"

class VectorCursos
{
private:
	Curso** lista;
	int tamanio;
	int cantidad;
public:
	VectorCursos(int tamanio)
	{
		this->lista = new Curso * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Curso* nuevocurso)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevocurso;
			cantidad++;
		}
		else
		{
			cout << "no se puede agregar nuevos Cursos " << endl;
		}

	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrar();
		}
	}
	Curso* buscarPorCodigo(int codigoBuscado)
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
	
	~VectorCursos()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
};