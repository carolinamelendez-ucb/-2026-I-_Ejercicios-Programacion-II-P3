#pragma once
#include <iostream>
#include <string>
#include "Curso.h"
using namespace std;

class VectorCursos {
private:
	Curso** cursos;
	int indice;
	int tamanio;
public:
	VectorCursos(int tamanio) {
		this->tamanio = tamanio;
		cursos = new Curso * [tamanio];
		this->indice = 0;
	}

	void agregar(Curso* nuevoCurso) {
		bool encontrado = false;
		if (indice < tamanio)
		{
			for (int i = 0; i < indice; i++) {
				if (nuevoCurso->getCodigo() == cursos[i]->getCodigo()) {
					cout << "Ya existe un curso con ese codigo" << endl;
					encontrado = true;
					break;
				}
			}
			if (!encontrado) {
				cursos[indice] = nuevoCurso;
				indice++;
			}
		}
		else {
			cout << "Se supero el limite de cursos" << endl;
		}

	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cout << endl;
			cursos[i]->mostrar();
		}
	}

	Curso* getCursoPorCodigo(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getCodigo() == codigo) {
				return cursos[i];
			}
		}
		cout << "No se encontro el curso con ese codigo" << endl;
		return nullptr;
	}
};