#pragma once
#include "socio.h"
class socioVector {
private:
	socio** socios;
	int tamanio;
	int indice;
public:
	socioVector(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->socios = new socio * [tamanio];

	}
	void agregar(socio* nuevo) {
		socios[indice] = nuevo;
		indice++;
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			socios[i]->mostrar();
		}
	}
	socio* obtener(int pos) {
		return socios[pos];
	}
};
