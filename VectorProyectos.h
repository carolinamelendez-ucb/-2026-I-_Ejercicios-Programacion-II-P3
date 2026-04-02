#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

using namespace std;

class VectorProyectos
{
private:
	Proyecto** lista;
	int tamanio;
	int cantidad;
public:
	VectorProyectos(int tamanio)
	{
		this->lista = new Proyecto * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}

	void agregar(Proyecto* nuevoProyecto)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoProyecto;
			cantidad++;
		}
		else
		{
			cout << "El vector esta lleno, nose puede agregar" << endl;
		}
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrarInfo();
		}
	}
	Proyecto* BuscarCodigo(int codigoBuscado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (lista[i]->getCodigo() == codigoBuscado)
			{
				return lista[i];
			}
		}
		return nullptr;
	}

	~VectorProyectos()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
	Proyecto* MayorCosto()
	{
		Proyecto* mayor = lista[0];
		for (int i = 0; i < cantidad; i++)
		{
			if (lista[i]->calcularCosto() > mayor->calcularCosto())
			{
				mayor = lista[i];
			}
		}
		return mayor;
	}
};
