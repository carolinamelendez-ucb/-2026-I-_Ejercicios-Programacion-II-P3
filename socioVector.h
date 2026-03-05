#pragma once
#include <iostream>
#include <string>
#include "socio.h"
using namespace std;

class socioVector {
private:
	Socio** socios;
	int tamanio;
	int indice;
public:
	socioVector(int tamanio) {
		this->socios = new Socio*[tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Socio* newSocio) {
		socios[indice] = newSocio;
		indice++;
	}
	void mostrarSocios() {
		for (int i = 0; i < indice; i++) {
			cout << "--> Socio " << i + 1 << endl;
			socios[i]->mostrar();
		}
	}
};
