#pragma once
#include <iostream>
#include "Organizador.h"
using namespace std;

class VectorOrganizadores {
private:
	Organizador** organizadores;
	int tamanio;
	int indice;
public:
	VectorOrganizadores(int tamanio)
	{
		this->organizadores = new Organizador*[tamanio];
		this->tamanio = tamanio;
		indice = 0;
	}
	void agregar(Organizador* nuevoOrganizador) {
		organizadores[indice] = nuevoOrganizador;
		indice++;
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			organizadores[i]->mostrar();
		}
	}

	Organizador* getOrganizador(int i) { return organizadores[i]; }
};