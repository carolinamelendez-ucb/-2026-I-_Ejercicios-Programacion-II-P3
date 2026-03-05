#pragma once
#include <iostream>
#include <string>
#include "socio.h"
class SocioVector {
private:
	Socio** socio;
	int tamanio;
	int indice;
public:
	SocioVector(int tamanio) {
		this->socio = new Socio * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void mostrarSocioVector() {
		for (int i = 0;i < indice;i++) {
			socio[i]->mostrarSocio();
		}
	}
};