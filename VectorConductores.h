#pragma once
#include <iostream>
#include <string>
#include "Operador.h"

using namespace std;


class VectorConductores
{
private:
	Operador** lista;
	int cantidad;
	int tamanio;
public:
	VectorConductores(int tamanio)
	{
		this->lista = new Operador * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Operador* nuevoOperador)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoOperador;
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
	Operador* buscarCi(int ciDuplicado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (ciDuplicado == lista[i]->getCi())
			{
				return lista[i];
			}
		}
		return nullptr;
	}
	float costoTotal()
	{
		float suma = 0;
		for (int i = 0; i < cantidad; i++)
		{
			suma = suma + lista[i]->calcularCostoGenerado();
		}
		return suma;
	}
	void mostrarMenorCosto()
	{
		Operador* menor = nullptr;
		float menorCosto = 0;

		for (int i = 0; i < cantidad; i++)
		{
			float costoActual = lista[i]->calcularCostoGenerado();

			if (costoActual > 0)
			{
				if (menor == nullptr || costoActual < menorCosto)
				{
					menor = lista[i];
					menorCosto = costoActual;
				}
			}
		}

		if (menor != nullptr)
		{
			cout << " MENOR COSTO " << endl;
			menor->mostrarInfo();
		}
	}
	~VectorConductores()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[] lista;
	}
};
