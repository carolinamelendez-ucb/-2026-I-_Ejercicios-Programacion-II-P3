#pragma once
#include <iostream>
#include <string>
#include "Alquiler.h"
using namespace std;
class VectorAlquileres {
private:
	Alquiler** alquileres;
	int tamanio;
	int indice;
public:
	VectorAlquileres(int tamanio)
	{
		this->alquileres = new Alquiler * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregar(Alquiler* nueAlquiler) {
		if (indice < tamanio) {
			alquileres[indice] = nueAlquiler;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			alquileres[i]->mostrar();
			cout << endl;
		}
	}
};