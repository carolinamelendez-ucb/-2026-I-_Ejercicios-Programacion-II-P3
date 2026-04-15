#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
using namespace std;

class VectorDocentes {
private:
	Docente** docentes;
	int indice;
	int tamanio;
public:
	VectorDocentes(int tamanio) {
		this->tamanio = tamanio;
		docentes = new Docente * [tamanio];
		this->indice = 0;
	}

	void agregar(Docente* nuevoDocente) {
		bool encontrado = false;
		if (indice < tamanio)
		{
			for (int i = 0; i < indice; i++) {
				if (nuevoDocente->getCi() == docentes[i]->getCi()) {
					cout << "Ya existe un docente con ese ci" << endl;
					encontrado = true;
					break;
				}
			}
			if (!encontrado) {
				docentes[indice] = nuevoDocente;
				indice++;
			}
		}
		else {
			cout << "Se supero el limite de docentes" << endl;
		}

	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cout << endl;
			docentes[i]->mostrar();
		}
	}

	Docente* getDocentePorCi(int ci) {
		for (int i = 0; i < indice; i++) {
			if (docentes[i]->getCi() == ci) {
				return docentes[i];
			}
		}
		cout << "No se encontro el docente con ese ci" << endl;
		return nullptr;
	}

	void mostrarDocenteMenosCobra() {
		float maximo = 0;
		int indiceActual = 0;
		for (int i = 0; i < indice; i++) {
			if (docentes[i]->salarioTotal() > maximo) {
				maximo = docentes[i]->salarioTotal();
				indiceActual = i;
			}
		}
		docentes[indiceActual]->mostrar();
	}
	
};