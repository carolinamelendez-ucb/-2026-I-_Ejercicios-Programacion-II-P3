#pragma once
#include "Vuelo.h"

class VectorVuelos {
private:
	int indice;
	int tamanio;
	Vuelo** vuelos;
public:
	VectorVuelos(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->vuelos = new Vuelo * [tamanio];
	}
	void agregarVuelos(Vuelo* newVuelo) {
		if (indice < tamanio) {
			vuelos[indice] = newVuelo;
			indice++;
		}
	}
	Vuelo* buscar(string codigo) {
		for (int i = 0; i < indice; i++) {
			if (vuelos[i]->getCodigo() == codigo)
				return vuelos[i];
		}
		return nullptr;
	}
};
