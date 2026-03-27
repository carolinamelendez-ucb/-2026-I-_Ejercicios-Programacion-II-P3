#pragma once
#include <iostream>
#include <string>
#include "Espectador.h"

using namespace std;

class VectorEspectador {
private:
	int tamanio;
	int indice;
	Espectador** espectadores;
public:

	VectorEspectador() = default;

	VectorEspectador(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->espectadores = new Espectador*[tamanio];
	}
	void agregar( Espectador* nuevoEspectador) {
		if (indice < tamanio) {
			espectadores[indice] = nuevoEspectador;
			indice++;
		}
		else {
			cout << "Ya no se pueden registrar mas Espectadores" << endl;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice; i++) {
			espectadores[i]->mostrar();
		}
	}
	~VectorEspectador() {
		for (int i = 0; i < indice; i++) {
			delete espectadores[i];
		}
		delete[]espectadores;
	}
};