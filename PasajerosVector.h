#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Pasajero.h"
using namespace std;
class PasajerosVector {
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	PasajerosVector(int tamanio) {
		this->pasajeros = new Pasajero * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Pasajero* nuevoPasajero) {
		pasajeros[indice] = nuevoPasajero;
		indice++;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			pasajeros[i]->mostrar();
			cout << "----------------" << endl;
		}
	}
	void mostrarPasajerosSinAsiento()
	{
		cout << "---- PASAJEROS SIN ASIENTO ----" << endl;
		bool encontrado = false;
		for (int i = 0; i < indice; i++) {
			if (pasajeros[i]->getNumeroAsiento() == 0)
			{
				pasajeros[i]->mostrar();
				cout << "--------------" << endl;
				encontrado = true;
			}
		}
		if (!encontrado) {
			cout << "no hay pasajeros sin asiento " << endl;
		}
	}
	void mostrarPasajerosAsientoImpar() {
		cout << "---- PASAJEROS CON ASIENTOS IMPAR ----" << endl;
		bool encontrado = false;
		for (int i = 0; i < indice; i++) {
			int asiento = pasajeros[i]->getNumeroAsiento();
			if (asiento != 0 && (asiento % 2 != 0)) {
				pasajeros[i]->mostrar();
				cout << "-------------" << endl;
				encontrado = true;
			}
		}
		if (!encontrado) {
			cout << "NO hay pasajeros con asiento impar." << endl;
		}
	}
	void mostrarPasajeroPorNombre(string nombreBuscado) {
		cout << "---- BUSQUEDA POR NOMBRE ----" << endl;
		for (int i = 0; i < indice; i++)
		{
			if (pasajeros[i]->getNombre() == nombreBuscado) {
				pasajeros[i]->mostrar();
				return;
			}
		}
		cout << "No se encontro pasjero con nombre: " << nombreBuscado << endl;
	}

	void mostrarPasajeroPorCi(int ciBuscado) {
		cout << "---- BUSQUEDA POR CI ----" << endl;
		for (int i = 0; i < indice; i++) {
			if (pasajeros[i]->getCi() == ciBuscado) {
				pasajeros[i]->mostrar();
				return;
			}
		}
		cout << "No se encontro pasajero con CI: " << ciBuscado << endl;
	}
};












