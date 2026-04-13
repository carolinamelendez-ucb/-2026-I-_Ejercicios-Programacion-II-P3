#pragma once
#include "Estudiante.h"

class VectorEstudiantes {
private:
	int indice;
	int tamanio;
	Estudiante** estudiantes;
public:
	VectorEstudiantes(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->estudiantes = new Estudiante * [tamanio];
	}

	void agregar(Estudiante* newEstudiante) {
		if (indice < tamanio) {
			estudiantes[indice] = newEstudiante;
			indice++;
		}
	}

	Estudiante* buscarCi(int ciBuscado) {
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getCI() == ciBuscado) {
				return estudiantes[i];
			}
		}
		return nullptr;
	}
	int getIndice() {
		return indice;
	}
	Estudiante* get(int i) {
		return estudiantes[i];
	}
};