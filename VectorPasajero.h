#pragma once
#include <iostream>
#include <string>
#include "Pasajero.h"
using namespace std;
class VectorPasajero {
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	VectorPasajero(int tamanio) {
		this->pasajeros = new Pasajero * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregarPasajero(Pasajero* nuePasajero) {
		for (int i = 0; i < indice; i++) {
			if (pasajeros[i]->getCI() == nuePasajero->getCI())
				throw exception();
		}
		if (indice < tamanio) {
			pasajeros[indice] = nuePasajero;
			indice++;
		}
	}
	Pasajero* buscar(int ciBuscado) {
		for (int i = 0; i < indice; i++) {
			if (pasajeros[i]->getCI() == ciBuscado) {
				return pasajeros[i];
			}
		}
		return nullptr;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cout << pasajeros[i]->getCI();
			if (pasajeros[i]->getAsientoAsignado() != nullptr) {
				cout << " - " << pasajeros[i]->getAsientoAsignado()->getCodigo();
				cout << endl;
			}
		}
	}
};
