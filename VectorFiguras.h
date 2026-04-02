#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;
class VectorFiguras {
private:
	int tamanio;
	int indice;
	Figura** figuras;
public:
	VectorFiguras(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->figuras = new Figura * [tamanio];
	}
	void calcularTodasLasAreas() {
		
		for (int i	= 0; i < indice; i++) {
			figuras[i]->calcularArea();
			cout << "Figura " << i + 1 << " - ";
			figuras[i]->mostrar();
		}
	}

	void agregar(Figura * nuevaFigura){
		if (indice < tamanio) {
			figuras[indice] = nuevaFigura;
			indice++;
		}
	}

	~VectorFiguras() {
		for (int i = 0; i < indice; i++) {
			delete figuras[i];
		}
		delete[] figuras;
	}

};