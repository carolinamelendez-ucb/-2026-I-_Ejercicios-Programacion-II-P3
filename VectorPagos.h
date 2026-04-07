#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;
class VectorPago {
private:
	Pago** pagos;
	int indice;
	int tamanio;
public:
	VectorPago(int tamanio) : tamanio(tamanio)
	{
		this->pagos = new Pago * [tamanio];
		this->indice = 0;
	}
	void agregarPago(Pago* nuevoPago) {
		if (indice < tamanio) {
			pagos[indice] = nuevoPago;
			indice++;
		}
	}
	void mostrarVectorPagos() {
		for (int i = 0; i < indice; i++) {
			cout << "Pago " << i + 1 << endl;
			pagos[i]->mostrarInformacion();
			cout << endl;
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
			total = total + pagos[i]->calcularMontoFinal();
		}
		return total;
	}
};