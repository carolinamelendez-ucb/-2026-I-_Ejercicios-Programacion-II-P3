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
	void ordenarPorNombre() {
		for (int i = 0; i < indice - 1; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (socios[i]->getNombre() > socios[j]->getNombre()) {
					Socio* aux = socios[i];
					socios[i] = socios[j];
					socios[j] = aux;
				}
			}
		}
	}
	void mostrarSocios() {
		for (int i = 0; i < indice; i++) {
			cout << "--> Socio " << i + 1 << endl;
			socios[i]->mostrar();
		}
	}
};
