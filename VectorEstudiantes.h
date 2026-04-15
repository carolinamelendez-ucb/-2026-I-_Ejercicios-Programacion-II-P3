#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"

using namespace std;

class VectorEstudiantes
{
private:
	Estudiante** lista;
	int tamanio;
	int cantidad;
public:
	VectorEstudiantes(int tamanio)
	{
		this->lista = new Estudiante * [tamanio];
		this->cantidad=0;
		this->tamanio = tamanio;
	}
	void agregar(Estudiante* nuevoEstudiante)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoEstudiante;
			cantidad++;
		}
		else
		{
			cout << "no se puede agregar nuevos estudiantes " << endl;
		}
		
	}
	Estudiante* buscarPorCi(int ciBuscado)
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
	float totalRecaudado()
	{
		float suma = 0;
		for (int i = 0; i < cantidad; i++)
		{
			suma = suma + lista[i]->calcularCosto();
		}
		return suma;
	}
	Estudiante* estudianteMasPaga()
	{
		Estudiante* mayor = lista[0];
		for (int i = 0; i < cantidad; i++)
		{
			if (lista[i]->calcularCosto() > mayor->calcularCosto())
			{
				mayor = lista[i];
			}
		}
		return mayor;
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrar();
			cout << "-----------------" << endl;
		}
	}
	~VectorEstudiantes() 
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
};


