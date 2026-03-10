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
			cout << endl;
		}
	}
	//metodo para obtener la posicion del metodo
	Socio* getSocio(int pos) {
		return socios[pos];
	}
	//metodo para ordenar alfabeticamente
	void ordenarNombres() {
		for (int i = 0; i < indice - 1; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (socios[i]->getNombre() > socios[j]->getNombre()) {
					Socio* temporal = socios[i];
					socios[i] = socios[j];
					socios[j] = temporal;
				}
			}
		}
	}

};

