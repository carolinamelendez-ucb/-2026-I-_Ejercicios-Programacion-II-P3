#pragma once
#include <iostream>
#pragma once
#include<string>
#include"Transporte.h"
class VectorTransporte {
private:
	Transporte** lista;
	int cantidad;
	int tamanio;
public:
	VectorTransporte(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->lista = new Transporte*[tamanio];
	}
	void Agregar(Transporte* nuevoTransporte){
		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getplaca() == nuevoTransporte->getplaca()) {
				cout << "placa duplicada" << endl;
				return;
			}
		}
		if (cantidad < tamanio) {
			lista[cantidad] = nuevoTransporte;
			cantidad++;
		}
	}
	Transporte* buscar(string placa) {
		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getplaca() == placa) {
				return lista[i];
			}
			return nullptr;
		}
	}

};