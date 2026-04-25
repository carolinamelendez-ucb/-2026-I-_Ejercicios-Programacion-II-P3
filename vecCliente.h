#pragma once
#include <iostream>
#include <string>
#include "clientes.h"
using namespace std;
class VecClientes {
private:
	Cliente** listacliente;
	int tamanio;
	int indice;
public:
	VecClientes(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->listacliente = new Cliente * [tamanio];
	}
	void agregar(Cliente* nuevoCliente) {
		if (tamanio > indice) {
			listacliente[indice] = nuevoCliente;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			listacliente[i]->mostrar();
		}
	}
};