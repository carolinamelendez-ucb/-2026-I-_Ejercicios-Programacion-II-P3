#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;
class VectorCliente {
private:
	Cliente** clientes;
	int tamanio;
	int indice;
public:
	VectorCliente(int tamanio)
	{
		this->clientes = new Cliente * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregar(Cliente* nueCliente) {
		if (indice < tamanio) {
			clientes[indice] = nueCliente;
			indice++;
		}
	}
	Cliente* buscar(int ci) {
		for (int i = 0; i < indice; i++) {
			if (clientes[i]->getCi() == ci) {
				return clientes[i];
			}
		}
		return nullptr;
	}
};