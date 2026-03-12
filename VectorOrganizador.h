#pragma once
#include <iostream>
#include <string>
#include "Organizador.h"

using namespace std;

class VectorOrganizador
{
private:
	Organizador** origanizadores;
	int tamnanio;
	int indice;
public:
	VectorOrganizador(int tamanio)
	{
		this->origanizadores = new Organizador* [tamanio];
		this->tamnanio = tamanio;
		this->indice = 0;
	}
	void agregar(Organizador* nuevoOrganizador)
	{
		origanizadores[indice] = nuevoOrganizador;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			origanizadores[i]->mostrar();
		}
	}

	//para ordenar

};

