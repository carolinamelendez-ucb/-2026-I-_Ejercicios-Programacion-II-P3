#pragma once
#include <iostream>
#include <string>
#include "Evento.h"
using namespace std;

class VectorEvento
{
private:
	Evento** eventos;
	int tamanio;
	int indice;
public:
	VectorEvento(int tamanio)
	{
		this->eventos = new Evento * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Evento* nuevoEvento)
	{
		eventos[indice] = nuevoEvento;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			eventos[i]->mostrar();
		}
	}

	Evento* buscar(int eventoId) {
		for (int i = 0; i < indice; i++)
		{
			if (eventos[i]->getId() == eventoId) {
				return eventos[i];
			}
		}
	}

	~VectorEvento() {
		for (int i = 0; i < indice; i++) {
			delete eventos[i];
		}

		delete[] eventos;
	}
};
