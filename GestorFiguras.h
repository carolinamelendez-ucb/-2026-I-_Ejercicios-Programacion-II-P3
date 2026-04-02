#pragma once
#include <iostream>
#include <string>
#include "VectorFiguras.h"
using namespace std;

class GestorFiguras {
private:
	vectorFiguras* listaFiguras;
public:
	GestorFiguras(int tamanio) {
		listaFiguras = new vectorFiguras(tamanio);
	}

	void registrarFigura(Figura* nuevaFigura) {
		listaFiguras->agregarFiguras(nuevaFigura);
	}

	void mostrarTodasLasAreas() {
		listaFiguras->calcularTodasLaAreas();
	}

	


};



