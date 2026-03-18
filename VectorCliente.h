#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;
class VectorCliente {
private:
	int tamanio;
	int indice;
	Cliente ** clientes;
public:


	VectorCliente() = default;
	VectorCliente(int tamanio)
		: tamanio(tamanio){
		this->indice = 0;
		this->clientes = new Cliente * [tamanio];
	}

	void agregar(Cliente * nuevoCliente) {
		if (indice < tamanio) {
			this->clientes[indice] = nuevoCliente;
			indice++;
		}
		else {
			cout << "No hay espacio para agregar nuevos clientes" << endl;
		}
		
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			clientes[i]->mostrar();
		}
	}

};