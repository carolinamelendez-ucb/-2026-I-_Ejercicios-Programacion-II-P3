#pragma once
#include <iostream>
#include <string>
#include "Pasajero.h"
using namespace std;
class PasajeroVector {
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	PasajeroVector(int tamanio) {
		this->pasajeros = new Pasajero*[tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Pasajero* nuePasajero) {
		pasajeros[indice] = nuePasajero;
		indice++;
	}
	void alumnosSinAsiento() {
		for (int i = 0;i < indice;i++) {

		}
	}
};