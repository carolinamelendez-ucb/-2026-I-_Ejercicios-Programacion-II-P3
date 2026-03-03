#pragma once
#include <iostream>
#include <string>
#include "pasajero.h"
using namespace std;
class pasajerosVector {
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	pasajerosVector(int tamanio) {
		this->pasajeros = new Pasajero * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Pasajero* newPasajero) {
		pasajeros[indice] = newPasajero;
		indice++;
	}
	void mostrarSinAsiento() {
		for (int i = 0; i < indice; i++) {
			if (pasajeros[i]->getAsiento() == 0) {
				pasajeros[i]->mostrar();
			}
		}
	}
};
