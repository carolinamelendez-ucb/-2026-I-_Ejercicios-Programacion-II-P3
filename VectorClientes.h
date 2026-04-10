#pragma once
#pragma once
#include "Cliente.h"

class VectorClientes
{
private:
	int indice; int tamanio;
	Cliente** clientes;


public:
	VectorClientes(int tamanio)
	{
		this->indice = 0;
		this->tamanio = tamanio;
		this->clientes = new Cliente * [tamanio];
	}

	void agregar(Cliente* nuevoCliente)
	{
		if (indice < tamanio)
		{
			clientes[indice] = nuevoCliente;
			indice++;
		}
	}

	Cliente* buscarCliente(int ci)
	{
		for (int i = 0; i < indice; i++)
		{
			if (clientes[i]->getCi() == ci)
			{
				return clientes[i];
			}
		}
		return nullptr;
	}
};
