#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class VectorEstudiante {
private:
	int tamanio;
	int indice;
	Estudiante** estudiantes;
public:

	VectorEstudiante() = default;

	VectorEstudiante(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->estudiantes = new Estudiante * [tamanio];
	}
	void agregar(Estudiante* nuevoEstudiante) {
		if (indice < tamanio) {
			estudiantes[indice] = nuevoEstudiante;
			indice++;
		}
		else {
			cout << "Total de registros disponibles:  " << tamanio << endl;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cout << "Estudiante " << i << " : " << endl;
			estudiantes[i]->mostrar();
		}
	}

	~VectorEstudiante() {
		for (int i = 0; i < indice; i++) {
			delete estudiantes[i];
		}
		delete[] estudiantes;
	}
};
