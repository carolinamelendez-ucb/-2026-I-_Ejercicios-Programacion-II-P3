#pragma once
#include <iostream>
#include <string>
#include "pasajero.h"
using namespace std;

class Pasajeros {
private:
	Pasajero** pasajero;
	int tamanio;
	int cantidad;
public:
	Pasajeros(int tamanio) {
		this->pasajero = new Pasajero * [tamanio];
		this->tamanio = tamanio;
		this->cantidad = 0;
	}
	void agregar(Pasajero* newpasajero) {
		pasajero[cantidad] = newpasajero;
		cantidad++;
	}
	void pasajerosinasiento() {
		for (int i = 0;i < cantidad;i++) {
			if (pasajero[i]->getasiento() > 0)
				pasajero[i]->mostrar();
		}
 }

};