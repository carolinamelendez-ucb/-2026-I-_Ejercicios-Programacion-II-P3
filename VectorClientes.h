#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;


class VectorClientes
{
private:
	Cliente** lista;
	int cantidad;
	int tamanio;
public:
	VectorClientes(int tamanio)
	{
		this->lista = new Cliente * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Cliente* nuevoCliente)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoCliente;
			cantidad++;
		}
		else
		{
			cout << "no hay espacio para registrar clinetes" << endl;
		}
	}
	Cliente* buscarPorNombre(string nombreBuscado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (nombreBuscado == lista[i]->getNombre())
			{
				return lista[i];
			}
		}
		return nullptr;
	}
	float calcularTotalGeneral()
	{
		float suma = 0;
		for (int i = 0; i < cantidad; i++)
		{
			suma = suma + lista[i]->calcularTotalCliente();
		}
		return suma;
	}
	
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrar();
		}
	}
	~VectorClientes()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
};

