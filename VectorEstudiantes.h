#pragma once
#include <iostream>
#include "Estudiante.h"

using namespace std;

class VectorEstudiantes {
private:
	Estudiante** estudiantes;
	int tamanio;
	int indice;
public:
	VectorEstudiantes(int tamanio) {
		this->tamanio = tamanio;
		this->estudiantes = new Estudiante * [tamanio];
		this->indice = 0;
	}

	void agregar(Estudiante* nuevoEstudiante) {
		estudiantes[indice] = nuevoEstudiante;
		indice++;
	}
};