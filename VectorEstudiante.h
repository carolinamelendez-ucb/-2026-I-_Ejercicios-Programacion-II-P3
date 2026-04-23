#pragma once
#include "Estudiante.h"

class VectorEstudiante {
private:
	int indice;
	int tamanio;
	Estudiante** listaEstudiantes;
public:
	VectorEstudiante(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->listaEstudiantes = new Estudiante * [tamanio];
	}
	void agregarEstudiante(Estudiante* newEstudiante) {
		if (indice < tamanio) {
			listaEstudiantes[indice] = newEstudiante;
			indice++;
		}
	}
};
