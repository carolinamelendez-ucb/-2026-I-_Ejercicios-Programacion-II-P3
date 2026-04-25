#pragma once
#pragma once
#include <iostream>
#include <string>
#include "sala.h"
using namespace std;
class VecSala {
private:
	Sala** listaFila;
	int tamanio;
	int indice;
public:
	VecSala(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->listaFila = new Sala * [tamanio];
	}
	void agregar(Sala* nuevoSala) {
		if (tamanio > indice) {
			listaFila[indice] = nuevoSala;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			listaFila[i]->mostrar();
		}
	}
};