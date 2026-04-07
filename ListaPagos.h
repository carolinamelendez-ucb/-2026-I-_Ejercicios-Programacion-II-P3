#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class VectoListaPagos {
private:
	int tamanio;
	int cantidad;
	Pago** listaPagos;
public:
	VectoListaPagos(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaPagos = new Pago * [tam];
	}

	void agregarLista(Pago* nvoPago){
		if (cantidad < tamanio) {
			listaPagos[cantidad] = nvoPago;
			cantidad++;
		}
	}

	double procesarTodo() {
		double totalCliente = 0;
		for (int i = 0;i < cantidad;i++) {
			cout << "Pago" << (i + 1) << ":" << endl;
			listaPagos[i]->mostrar();
			cout << endl;
			totalCliente += listaPagos[i]->calcularMonto();
		}
		return totalCliente;
	}

};