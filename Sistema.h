#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;

class Sistema {
private:
	Cliente** clientes;
	int tamanio;
	int cantidad;
public:
	Sistema(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->clientes = new Cliente * [tam];
	}

	void procesarSistema() {
		double totalGeneral = 0;
		for (int i = 0;i < cantidad;i++) {
			totalGeneral += clientes[i]->procesarPagos();
		}
		cout << "Total general Procesado:" << totalGeneral << endl;
	}
};
