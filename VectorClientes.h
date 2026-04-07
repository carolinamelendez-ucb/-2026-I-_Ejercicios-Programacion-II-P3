#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;
class VectorClientes {
private:
	Cliente** clientes;
	int indice;
	int tamanio;
public:
	VectorClientes(int tamanio) : tamanio(tamanio)
	{
		this->clientes = new Cliente * [tamanio];
		this->indice = 0;
	}
	void agregarCliente(Cliente* nuevoCliente) {
		if (indice < tamanio) {
			clientes[indice] = nuevoCliente;
			indice++;
		}
	}
	void mostrarVectorClientes() {
		for (int i = 0; i < indice; i++) {
			clientes[i]->mostrarCliente();
			cout << endl;
		}
	}
	Cliente* existeCI(int ci) {
		for (int i = 0; i < indice; i++) {
			if (clientes[i]->getCi() == ci) {
				return clientes[i];
			}
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
			total = total + clientes[i]->sumarPagos();
		}
		return total;
	}
};