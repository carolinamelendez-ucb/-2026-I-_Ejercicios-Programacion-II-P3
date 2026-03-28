#pragma once
#include "Estudiante.h"

class VectorEstudiantes {
private:
	Estudiante** estudiantes;
	int indice;
	int tamanio;
public:
	VectorEstudiantes(int tamanio) {
		this->estudiantes = new Estudiante * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregarEstudiante(Estudiante* nuevoEstudiante) {
		if (indice < tamanio) {
			estudiantes[indice] = nuevoEstudiante;
			indice++;
		}
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			estudiantes[i]->mostrar();
		}
	}
};