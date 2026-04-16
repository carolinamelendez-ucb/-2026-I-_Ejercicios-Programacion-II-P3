#pragma once
#include "Docente.h"

class VectorDocentes {
private:
	int indice;
	int tamanio;
	Docente** arrayDocentes;
public:
	VectorDocentes(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->arrayDocentes = new Docente * [tamanio];
	}

	void agregar(Docente* nuevoDocente) {
		if (indice < tamanio) {
			arrayDocentes[indice] = nuevoDocente;
			indice++;
		}
	}
	Docente*buscarPorCi(string ciBuscado) {
		for (int i = 0; i < indice; i++) {
			if (arrayDocentes[i]->getCi() == ciBuscado) {
				return arrayDocentes[i];
			}
		}

		return nullptr;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			arrayDocentes[i]->mostrar();
			cout << "------------------" << endl;
		}
	}

	Docente* docenteQueMenosGana() {
		Docente* menor = nullptr;
		for (int i = 0; i < indice; i++) {
			if (menor == nullptr || arrayDocentes[i]->calcularSalario() < menor->calcularSalario()) {
				menor = arrayDocentes[i];
			}
		}
		return menor;
	}
	~VectorDocentes() {
		for (int i = 0; i < indice; i++) {
			delete arrayDocentes[i];
		}
		delete[] arrayDocentes;
	}
};