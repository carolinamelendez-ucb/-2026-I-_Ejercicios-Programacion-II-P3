#pragma once
#include "Curso.h"

class VectorCursos {
private:
	int indice;
	int tamanio;
	Curso** arrayCursos;
public:
	VectorCursos(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->arrayCursos = new Curso * [tamanio];
	}

	void agregar(Curso* nuevoCurso) {
		if (indice < tamanio) {
			arrayCursos[indice] = nuevoCurso;
			indice++;
		}
	}


	Curso* buscarPorCodigo(string codigoBuscado) {
		for (int i = 0; i < indice; i++) {
			if (arrayCursos[i]->getCodigo() == codigoBuscado) {
				return arrayCursos[i];
			}
		}

		return nullptr;
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			arrayCursos[i]->mostrar();
		}
	}
	~VectorCursos() {
		for (int i = 0; i < indice; i++) {
			delete arrayCursos[i];
		}
		delete[] arrayCursos;
	}

};