#pragma once
#include <string>
#include <iostream>
#include "Estudiante.h"
using namespace std;
class VecEstudiante {
private:
	Estudiante** listaEstudiante;
	int tamanio;
	int indice;
public:
	VecEstudiante(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->listaEstudiante = new Estudiante * [tamanio];
	}
	void agregar(Estudiante* nuevoEstudiante) {
		if (tamanio > indice) {
			listaEstudiante[indice] = nuevoEstudiante;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			listaEstudiante[i]->mostrar();

		}
	}
};