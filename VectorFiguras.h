#pragma once
#include "Figura.h"

class VectorFiguras
{
private:
	Figura** figuras;
	int indice;
	int tamanio;

public:

	VectorFiguras(int tamanio)
	{
		this->tamanio = tamanio;
		this->indice = 0;
		this->figuras = new Figura * [tamanio];
	}

	void agregar(Figura* nuevaFigura)
	{
		if (indice < tamanio)
		{
			figuras[indice] = nuevaFigura; \
				indice++;
		}
	}

	void calcularTodasLasAreas() {
		for (int i = 0; i < indice; i++) {
			cout << "figura " << i + 1
				<< " area: " << figuras[i]->calcularArea();
				cout << endl;
		}
	}

	~VectorFiguras() {
		for (int i = 0; i < indice; i++) {
			delete figuras[i];
		}
		delete[] figuras;
	}
};