#pragma once

#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;
class VectorCliente {
private:
	int tamanio;
	int indice;
	Cliente** clientes;
public:

	VectorCliente(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->clientes = new Cliente * [tamanio];
	}
	void agregar(Cliente* nuevoCliente) {
		if (indice < tamanio) {
			clientes[indice] = nuevoCliente;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			clientes[i]->mostrar();
			cout << endl;
		}
	}
	Cliente * existeCi(int ci) {
		for(int i=0; i<indice; i++)
			if (clientes[i]->getCi() == ci) {
				return clientes[i];
			}
		return nullptr;
	}
	void procesarPagosClientes() {
		for (int i = 0; i < indice; i++) {
			clientes[i]->procesarPagos();
		}
	}

	double sumarPagosClientes() {
		double total = 0;

		for (int i = 0; i < indice; i++) {
			total =total + clientes[i]->sumarPagos();
		}

		return total;
	}

};