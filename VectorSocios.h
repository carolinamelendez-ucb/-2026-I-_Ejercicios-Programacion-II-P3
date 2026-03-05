#pragma once
#include<iostream>
#include<string>
#include "Socio.h"
using namespace std;

class VectorSocios {
private:
	Socio** socios;
	int tamanio;
	int indice;
public:
	VectorSocios (int tamanio) {
		this->socios = new Socio * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Socio* nuevoSocio) {
		socios[indice] = nuevoSocio;
		indice++;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			socios[i]->mostrar();
		}
	}
};

