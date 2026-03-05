#pragma once
#include <iostream>
#include <string>
#include "Socio.h"
using namespace std;

class VectorSocio {
private:
	Socio** socios;
	int indice;
	int tamanio;
public:
	VectorSocio(int tamanio) {
		this->socios = new Socio * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Socio* nuevoSocio)
	{
		socios[indice] = nuevoSocio;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			socios[indice]->mostrar();
		}
	}
};




