#pragma once
#include <iostream>
#include "Socio.h"

using namespace std;

class VectorSocios {
private:
	Socio** socios;
	int tam;
	int indice;
public:
	VectorSocios(int tam){
		this->socios = new Socio * [tam];
		this->tam = tam;
		this->indice = 0;
	}
	void agregar(Socio* socio) {
		socios[indice] = socio;
		indice++;
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			cout << endl << "SOCIO N°" << i + 1 << ":" << endl;
			socios[i]->mostrar();
		}
	}
};