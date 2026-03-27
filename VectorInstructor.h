#pragma once
#include <iostream>
#include <string>
#include "Instructor.h"
#include <algorithm>

using namespace std;

class VectorInstructor {
private:
	int tamanio;
	int indice;
	Instructor** instructores;
public:

	VectorInstructor() = default;

	VectorInstructor(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->instructores = new Instructor * [tamanio];
	}
	
	void agregar(Instructor* nuevoInstructor) {
		if (indice < tamanio) {
			instructores[indice] = nuevoInstructor;
			indice++;
		}
		else {
			cout << "Total de registros disponibles:  " << tamanio << endl;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			instructores[i]->mostrar();
		}
	}
	

	Instructor* AsignarInstructorMenorCantidad() {
	Instructor* instructorMenor = nullptr;

		for (int i = 0; i < indice; i++) {
			if (instructores[i]->getEstado()) {

				if (instructorMenor==nullptr || instructores[i]->getCantidadCursosR() < instructorMenor->getCantidadCursosR()) {
					instructorMenor = instructores[i];
				}
			}
		}
		return instructorMenor;
	}
	void ordenarPorCurso() {
		sort(instructores, instructores + indice, [](Instructor*  a, Instructor *b) {
			return a->getCantidadCursosR() > b->getCantidadCursosR();
			}
		);

	}
	Instructor * mayorCantidad() {
		Instructor* auxInstructor = nullptr;
		for (int i = 0; i < indice; i++) {
			if (auxInstructor == nullptr || instructores[i]->getCantidadCursosR() > auxInstructor->getCantidadCursosR()) {
				auxInstructor = instructores[i];
			}
		}
		return auxInstructor;
	}

	~VectorInstructor() {
		for (int i = 0; i < indice; i++) {
			delete instructores[i];
		}
		delete[] instructores;
	}

};
