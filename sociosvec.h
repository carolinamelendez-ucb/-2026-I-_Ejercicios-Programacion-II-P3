#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "socios.h"
class Sociovec {
private:
	Socio** socios;
	int tamanio;
	int indice;
public:
	Sociovec(int tamanio) {
		this->socios = new Socio * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Socio* nuevosocio) {
		socios[indice] = nuevosocio;
		indice++;
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			socios[i]->mostrar();
		}
	}
};