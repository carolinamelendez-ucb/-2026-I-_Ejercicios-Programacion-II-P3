#pragma once
#include "Curso.h"


class VectorCursos {
private:
	int tamanio;
	int indice;
	Curso** cursos;
public:


	VectorCursos(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->cursos = new Curso * [tamanio];
	}
	void agregarCurso(Curso* nuevoCurso) {
		if (indice < tamanio) {
			cursos[indice] = nuevoCurso;
			indice++;
		}
	}
	Curso* buscarCodigoDuplicado(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getCodigo() == codigo) {
				return cursos[i];
			}
		}
		return nullptr;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {

			cursos[i]->mostrar();
			cout << endl;
		}
	}
};
