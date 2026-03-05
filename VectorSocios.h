#pragma once
#include <iostream>
#include "Socio.h"

using namespace std;

class SociosVector {
private:
	Socio** socios;
	int tamanio;
	int indice;

public:
	SociosVector(int tamanio) {
		this->socios = new Socio * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}

	void agregar(Socio* nuevoSocio) {
		socios[indice] = nuevoSocio;
		indice++;
	}

	void mostrarSocios() {
		for (int i = 0;i != indice;i++) {
			cout << "SOCIO " << i + 1 << endl;
			socios[i]->mostrar();
			cout << endl;
		}
	}
};