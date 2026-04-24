#pragma once
#include <iostream>
#include <string>
#include "Vuelo.h"
using namespace std;
class VectorVuelo {
	Vuelo** vuelos;
	int tamanio;
	int indice;
public:
	VectorVuelo(int tamanio) {
		this->vuelos = new Vuelo * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregarVuelos(Vuelo* nueVuelo) {
		if (indice < tamanio) {
			vuelos[indice] = nueVuelo;
			indice++;
		}
		else {
			cout << "No se pueden agregar más vuelos..." << endl;
		}
	}
	Vuelo* buscar(string codigoBuscado) {
		for (int i = 0; i < indice; i++) {
			if (vuelos[i]->getCodigo() == codigoBuscado) {
				return vuelos[i];
			}
		}
		return nullptr;
	}
};