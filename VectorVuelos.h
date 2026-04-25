#pragma once
#include <iostream>
#include <string>
#include "Vuelo.h"

using namespace std;

class VectorVuelos {
private:
	int indice;
	int tamanio;
	Vuelo** vuelos;
public:
	VectorVuelos(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->vuelos = new Vuelo * [tamanio];
	}

	void agregar(Vuelo* vueloNuevo) {
		if (indice >= tamanio) {
			cout << "No se pueden agregar mas vuelos" << endl;
		}
		else {
			vuelos[indice] = vueloNuevo;
			indice++;
		}
	}

	Vuelo* buscarCodigo(int codigo) {
		for (int i = 0; i != indice; i++) {
			if (vuelos[i]->getCodigo() == codigo) {
				return vuelos[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0; i != indice; i++) {
			vuelos[i]->mostrarPasajeros();
			vuelos[i]->estadoAsientos();
		}
	}

	~VectorVuelos() {
		for (int i = 0; i != indice; i++) {
			delete vuelos[i];
		}
		delete[] vuelos;
	}
};
