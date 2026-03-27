#pragma once
#include "Evento.h"
class ListaEventos
{
private:
	Evento** lista;
	int ind;
	int tamanio;
public:
	ListaEventos(int tamanio)
	{
		this->lista = new Evento * [tamanio];
		this->ind = 0;
		this->tamanio = tamanio;
	}
	void registrar(Evento* evento)
	{
		if (ind < tamanio)
		{
			lista[ind] = evento;
			ind++;
		}
	}
	void mostrarEvento()
	{
		cout << "Eventos:";
		for (int i = 0; i < ind; i++)
		{
			lista[i]->Mostrar();
		}
	}
	void buscarEvento(int id,Invitado* invitado)
	{
		for (int i = 0; i < ind; i++)
		{
			if (id == lista[i]->getID())
			{
				lista[i]->agregarInvitado(invitado);
			}
		}
	}
	void finalizarEventos(int id)
	{
		for (int i = 0; i < ind; i++)
		{
		
			if (lista[i]->getID())
			{
				lista[i]->finalizar();
			}

		}
	}
};

