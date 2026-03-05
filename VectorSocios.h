#pragma once
#include "Socio.h"
#include <iostream>
#include <string>

using namespace std;
class VectorSocios
{
private:
	int indice;
	int tamanio;
	Socio** socios;
public:
	VectorSocios(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->socios = new Socio* [tamanio];
	}
	void mostrar() {
		for (int i = 0; i < tamanio; i++)
		{
			socios[i]->mostrar();
		}
	}
	void agregar(Socio* nuevoSocio) {
		socios[indice] = nuevoSocio;
		indice++;
	}
};

