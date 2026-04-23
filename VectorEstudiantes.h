#pragma once
#include "Estudiante.h"
using namespace std;

class VectorEstudiantes {
private:
	int tamanio;
	int indice;
	Estudiante** estudiantes;
public:
	VectorEstudiantes(int tamanio) :tamanio(tamanio), indice(0) {
		this->estudiantes = new Estudiante * [tamanio];
	}

	void agregar(Estudiante* nuevoElemento) {
		estudiantes[indice] = nuevoElemento;
		indice++;
	}

	Estudiante* estudianteCi(int ci) {
		for (int i = 0;i < indice;i++) {
			if (estudiantes[i]->getCi() == ci) {
				return estudiantes[i];
			}
		}
	}
};