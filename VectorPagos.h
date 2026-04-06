#pragma once

#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class VectorPago {
private:
	int tamanio;
	int indice;
	Pago** pagos;
public:

	VectorPago(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->pagos = new Pago * [tamanio];
	}
	void agregar(Pago * nuevoPago) {
		if (indice < tamanio) {
			pagos[indice] = nuevoPago;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cout << "Pago " << i + 1 << ": " << endl;
			pagos[i]->mostrar();
		}
	}
	void procesarPagos() {
		for (int i = 0; i < indice; i++) {
			pagos[i]->calcularMontoFinal();
		}
	}
	double sumarPagos() {
		double total = 0;

		for (int i = 0; i < indice; i++) {
			total += pagos[i]->calcularMontoFinal();
		}

		return total;
	}
};
