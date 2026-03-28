#pragma once
#include "Curso.h"

class VectorCursos {
private:
	Curso** cursos;
	int indice;
	int tamanio;
public:
	VectorCursos(int tamanio) {
		this->cursos = new Curso * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregarCurso(Curso* nuevoCurso) {
		if (indice < tamanio) {
			cursos[indice] = nuevoCurso;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			cursos[i]->mostrar();
		}
	}

	void asignarEstudianteACurso(int id, Estudiante* nuevoEstudiante) {
		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getId() == id) {
				cursos[i]->agregarEstudiante(nuevoEstudiante);
			}
		}
	}
	void finalizarCurso(int id) {
		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getId() == id) {
				cursos[i]->finalizarCurso();
			}
		}
	}
};