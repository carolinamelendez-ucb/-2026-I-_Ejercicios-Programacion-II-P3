#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class VectorEstudiantes {
private:
	Estudiante** estudiantes;
	int indice;
	int tamanio;
public:
	VectorEstudiantes(int tamanio) {
		this->tamanio = tamanio;
		estudiantes = new Estudiante * [tamanio];
		this->indice = 0;
	}

	void agregar(Estudiante* nuevoEstudiante) {
		bool encontrado = false;
		if(indice<tamanio)
		{
			for (int i = 0; i < indice; i++) {
				if (nuevoEstudiante->getCi() == estudiantes[i]->getCi()) {
					cout << "Ya existe un estudiante con ese ci" << endl;
					encontrado = true;
					break;
				}
			}
			if (!encontrado) {
				estudiantes[indice] = nuevoEstudiante;
				indice++;
			}
		}
		else {
			cout << "Se supero el limite de estudiantes" << endl;
		}
		
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cout << endl;
			estudiantes[i]->mostrar();
		}
	}

	Estudiante* getEstudiantePorCi(int ci) {
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getCi() == ci) {
				return estudiantes[i];
			}
		}
		cout << "No se encontro el estudiante con ese ci" << endl;
		return nullptr;
	}

	void mostrarEstudianteMasPaga() {
		float maximo = 0;
		int indiceActual = 0;
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->costoTotal() > maximo) {
				maximo = estudiantes[i]->costoTotal();
				indiceActual = i;
			}
		}
		estudiantes[indiceActual]->mostrar();
	}
};