#pragma once
#include <iostream>
#include "Estudiante.h"
#include <string>
using namespace std;

class VectorEstudiantes {
private:
	int tamanio;
	int indice;
	Estudiante** estudiantes;
public:
	VectorEstudiantes(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->estudiantes = new Estudiante * [tamanio];
	}
	void agregar(Estudiante* nuevoEstudiante) {
		if (indice < tamanio) {
			estudiantes[indice] = nuevoEstudiante;
			indice++;
		}
	}
	Estudiante* buscarCi(int ci) {
		Estudiante* aux = nullptr;
		for (int i = 0; i < indice; i++) {
			if (aux == nullptr || aux->getCi() == ci) {
				return aux;
			}
		}
		return aux;
	}
};