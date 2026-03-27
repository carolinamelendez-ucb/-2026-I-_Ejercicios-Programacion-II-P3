#pragma once
#include "Organizador.h"
class ListaOrganizadores
{
private:
	Organizador** lista;
	int ind;
	int tamanio;
public:
	ListaOrganizadores(int tamanio)
	{
		this->lista = new Organizador * [tamanio];
		this->ind = 0;
		this->tamanio = tamanio;
	}
	void buscarOrganizador()
	{

	}
	void registrarOrganizador(Organizador* organizador)
	{
		if (ind < tamanio)
		{
			lista[ind] = organizador;
			ind++;
		}
	}
	void OrdenarOrganizadores()
	{
		for (int i = 0; i < ind - 1; i++) 
		{
			for (int j = 0; j < ind - 1 - i; j++) 
			{
				if (lista[j]->getEventos() < lista[j + 1]->getEventos())
				{
					// Intercambio
					Organizador* temp = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = temp;
				}
			}
			
		}
	}
	void mostrar()
	{
		for (int i = 0; i < ind; i++)
		{
			cout << "repartidores" << endl;
			lista[i]->mostrar();
		}
	}
	Organizador* BuscarLibre()
	{
		for (int i = 0; i < ind; i++)
		{
			if (lista[i]->disponible() == true)
			{
				return lista[i];
			}
		}
		return nullptr;
	}
	Organizador* BuscarmayorRank()
	{
		OrdenarOrganizadores();
		for (int i = 0; i < ind; i++)
		{
			if (lista[i]->disponible() == true)
			{
				return lista[i];
			}
		}
		return nullptr;
	}
};
