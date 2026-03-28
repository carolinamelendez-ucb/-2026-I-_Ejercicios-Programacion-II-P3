#pragma once
#include <iostream>
#include <string>
#include "Espectador.h"
using namespace std;
class VectorEspectador {
private:
	Espectador** espectadores;
	int indice;
	int tamanio;
public:
	VectorEspectador(int tamanio) : tamanio(tamanio), indice(0) {
		espectadores = new Espectador * [tamanio];
	}
	~VectorEspectador() {
		for (int i = 0; i < indice; i++) {
			delete espectadores[i];
		}
		delete[] espectadores;
	}
	void agregarEspectadores(Espectador* nueEspectador) {
		if (indice < tamanio) {
			espectadores[indice] = nueEspectador;
			indice++;
		}
		else {
			cout << "Funcion llena" << endl;
		}
	}
	void mostrarVectorEspectadores() {
		for (int i = 0; i < indice; i++) {
			espectadores[i]->mostrarEspectador();
			cout << endl;
		}
	}
	int getCantidad() {
		return indice;
	}
};