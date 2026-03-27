#pragma once
#include <iostream>
#include <string>
#include "Curso.h"
using namespace std;

class VectorCurso {
private:
	int tamanio;
	int indice;
	Curso** cursos;
public:

	VectorCurso() = default;

	VectorCurso(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->cursos = new Curso * [tamanio];
	}
	
	void agregar(Curso * nuevoCurso) {
		if (indice < tamanio) {
			cursos[indice] = nuevoCurso;
			indice++;
		}
		else {
				cout << "Total de registros disponibles:  " << tamanio << endl;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cursos[i]->mostrar();
		}
	}
	
	Curso* getCurso(int id) {

		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getId() == id) {
				return cursos[i];
			}
		}
		return nullptr;
	}
	
	~VectorCurso() {
		for (int i = 0; i < indice; i++) {
			delete cursos[i];
		}
		delete[] cursos;
	}

};
