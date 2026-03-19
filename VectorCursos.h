#pragma once
#include <iostream>
#include "Curso.h"

using namespace std;

class VectorCursos {
private:
	Curso** cursos;
	int tamanio;
	int indice;
public:
	VectorCursos(int tamanio) {
		this->tamanio = tamanio;
		this->cursos = new Curso * [tamanio];
		this->indice = 0;
	}

	int getIndice() const { return indice; }

	void agregar(Curso* nuevoCurso) {
		cursos[indice] = nuevoCurso;
		indice++;
	}

	void asignarInstructor(Instructor* instructor, int i) {
		cout << "Este para el curso " << cursos[i]->getNombre() << endl;
		cursos[i]->asignarInstructor(instructor);
	}

	
	Curso* buscarPorId(int id) {
		for (int i = 0; i < indice; i++) {
			if (cursos[i]->getId() == id)
				return cursos[i];
		}
		return nullptr;
	}

	
	void finalizarCurso(int id) {
		Curso* curso = buscarPorId(id);
		if (curso != nullptr) {
			curso->finalizar();
		}
		else {
			cout << "Curso con ID " << id << " no encontrado." << endl;
		}
	}
};