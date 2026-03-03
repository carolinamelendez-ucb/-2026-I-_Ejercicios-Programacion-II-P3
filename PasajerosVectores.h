#pragma once
#include <iostream>
#include <string>
#include "Pasajero.h"

using namespace std;

class PasajerosVectores {
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	PasajerosVectores(int tamanio) {
		this->pasajeros = new Pasajero * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}

	void agregar(Pasajero* nuevoPasajero) {
		pasajeros[indice] = nuevoPasajero;
		pasajeros[indice]->asignarAsiento(indice + 1);
		indice++;
	}

	void mostrarSinAsientos() {
		cout << "Los pasajero sin asiento son:" << endl;
		for (int i = 0;i < indice;i++) {
			if (pasajeros[i]->getNumeroAsiento() == 0) {
				pasajeros[i]->mostrar();
			}
		}
	}

	void mostrarAsientosImpares() {
		cout << "Los pasajeros con asientos impaes son: " << endl;
		for (int i = 0;i < indice;i++) {
			if (pasajeros[i]->getNumeroAsiento()%2 != 0) {
				pasajeros[i]->mostrar();
			}
		}
	}

	void mostrarConNombre(string nombre) {
		for (int i = 0;i < indice;i++) {
			if (pasajeros[i]->getNombre()==nombre) {
				pasajeros[i]->mostrar();
			}
		}
	}

	void mostrarConCi(int ci) {
		for (int i = 0;i < indice;i++) {
			if (pasajeros[i]->getCi() == ci) {
				pasajeros[i]->mostrar();
			}
		}
	}
	//para comprobar los que no tienen asientos
	void errorSistema() {
		pasajeros[0]->asignarAsiento(0);
		pasajeros[2]->asignarAsiento(0);
	}
};