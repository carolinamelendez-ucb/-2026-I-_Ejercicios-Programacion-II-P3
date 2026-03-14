#pragma once
#include <iostream>
#include <string>
#include "Invitado.h"
using namespace std;

class VectorInvitado
{
private:
	Invitado** invitados;
	int tamanio;
	int indice;
public:
	VectorInvitado(int tamanio)
	{
		this->invitados = new Invitado * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Invitado* nuevoInvitado)
	{

		invitados[indice] = nuevoInvitado;
		indice++;

	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			invitados[i]->mostrar();
		}
	}

	~VectorInvitado() {
		for (int i = 0; i < indice; i++) {
			delete invitados[i];
		}

		delete[] invitados;
	}
};
