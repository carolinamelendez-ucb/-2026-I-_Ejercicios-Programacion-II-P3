#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;
class VectorTransporte {
private:
	int tamanio;
	int indice;
	Transporte** transportes;
public:
	VectorTransporte(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->transportes = new Transporte * [tamanio];
	}
	void agregar(Transporte* nuevoTRansporte) {
		if (indice < tamanio) {
			transportes[indice] = nuevoTRansporte;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++)
		{
			transportes[i]->mostrar();
		}
	}
	Transporte * existeTransporte(Transporte * auxTransporte) {

		for (int i = 0; i < indice; i++) {
			if (transportes[i]->getNumPlaca() == auxTransporte->getNumPlaca()) {
				return auxTransporte;
			}
		}
		return nullptr;
	}


};