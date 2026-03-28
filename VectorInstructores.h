#pragma once
#include "Intructores.h"

class VectorInstructores {
private:
	Instructor** instructores;
	int indice;
	int tamanio;
public:
	VectorInstructores(int tamanio) {
		this->instructores = new Instructor * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}

	void agregarInstructor(Instructor* nuevoInstructor) {
		if (indice < tamanio) {
			instructores[indice] = nuevoInstructor;
			indice++;
		}
	}
	void ordenamientoPorCursos() {
		for (int i = 0; i < indice; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (instructores[i]->getCantidadCursos() > instructores[j]->getCantidadCursos()) {
					Instructor* aux = instructores[i];
					instructores[i] = instructores[j];
					instructores[j] = aux;
				}
			}
		}
	}

	Instructor* comprobarDisponibilidad() {
		for (int i = 0; i < indice; i++) {
			if (instructores[i]->getEstado() == true) {
				return instructores[i];
			}
		}
		
		return nullptr;
	}

	void buscarAlInstructorConMayorCursos() {
		int may = instructores[0]->getCantidadCursos();
		int pos;
		for (int i = 1; i < indice; i++) {
			if (instructores[i]->getCantidadCursos() > may) {
				may = instructores[i]->getCantidadCursos();
				pos = i;
			}
		}
		cout << "El instructor con mas cursos dados es: " << instructores[pos]->getNombre() << endl;
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			instructores[i]->mostrar();
		}
	}
};