#pragma once
#include "Vuelo.h"

class VectorVuelos {
private:
	int tamanio;
	int cantidad;
	Vuelo** listaVuelos;
public:
	VectorVuelos(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaVuelos = new Vuelo * [tam];
	}

	void agregarP(Vuelo* nvoVuelos) {
		if (cantidad < tamanio) {
			listaVuelos[cantidad] = nvoVuelos;
			cantidad++;
		}
		else {
			cout << "No se pueden agregar mas Vuelos" << endl;
		}
	}

	Vuelo* buscarCodigoV(int CodigoBuscado) {
		for (int i = 0;i < cantidad;i++) {
			if (CodigoBuscado == listaVuelos[i]->getCodigoV()){
				return listaVuelos[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			listaVuelos[i]->mostrarV();
		}
	}



};