#pragma once
#include "Curso.h"

class VectorCursos {
private:
	int indice;
	int tamanio;
	Curso** cursos;
public:
	VectorCursos(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->cursos = new Curso * [tamanio];
	}

	void agregar(Curso* newCurso) {
		if (indice < tamanio) {
			cursos[indice] = newCurso;
			indice++;
		}
	}
	Curso* buscarCodigo(int codigoBuscado) {
		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getCodigo() == codigoBuscado) {
				return cursos[i];
			}
		}
		return nullptr;
	}
	int getIndice() {
		return indice;
	}
	Curso* get(int i) {
		return cursos[i];
	}
};
