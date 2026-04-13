#pragma once
#include "Docente.h"

class VectorDocentes {
private:
	int indice;
	int tamanio;
	Docente** docentes;
public:
	VectorDocentes(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->docentes = new Docente * [tamanio];
	}

	void agregar(Docente* newDocente) {
		if (indice < tamanio) {
			docentes[indice] = newDocente;
			indice++;
		}
	}
	Docente* buscarCi(int ciBuscado) {
		for (int i = 0; i < indice; i++) {
			if (docentes[i]->getCI() == ciBuscado) {
				return docentes[i];
			}
		}
		return nullptr;
	}
	int getIndice() {
		return indice;
	}
	Docente* get(int i) {
		return docentes[i];
	}
};
