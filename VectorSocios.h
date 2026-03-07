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

	Socio* getSocio(int pos) {
		return socios[pos];
	}

	void mostrarSocios() {

		for (int i = 0; i < indice; i++) {

			cout << "SOCIO " << i + 1 << endl;
			socios[i]->mostrar();
			cout << endl;
		}
	}

	void ordenarAlfabetico() {

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
};