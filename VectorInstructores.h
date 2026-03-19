#pragma once
#include <iostream>
#include "Instructor.h"
using namespace std;

class VectorInstructores {
private:
	Instructor** instructores;
	int tamanio;
	int indice;
public:
	VectorInstructores(int tamanio) {
		this->tamanio = tamanio;
		this->instructores = new Instructor * [tamanio];
		this->indice = 0;
	}

	void agregar(Instructor* nuevoInstructor) {
		instructores[indice] = nuevoInstructor;
		indice++;
	}

	Instructor* buscarLibreConMenosCursos() {
		int indiceActual = 0;
		int cantidadCursosActual = 9999;
		bool encontrado = false;
		for (int i = 0; i < indice; i++) {
			if ((instructores[i]->getEstado()) && (instructores[i]->getCursosRealizados() <= cantidadCursosActual)) {
				indiceActual = i;
				encontrado = true;
				cantidadCursosActual = instructores[i]->getCursosRealizados();
			}
		}
		if (encontrado) {
			cout << endl << "Se asigno el Instructor: " << endl;
			instructores[indiceActual]->mostrar();
			instructores[indiceActual]->cambiarEstadoOcupado();
			return instructores[indiceActual];
		}
		else {
			cout << endl << "No hay un instructor disponible" << endl;
			return nullptr;
		}
	}

	
	void mostrarOrdenadosPorCursos() {
		Instructor** copia = new Instructor * [indice];
		for (int i = 0; i < indice; i++) copia[i] = instructores[i];

		for (int i = 0; i < indice - 1; i++) {
			for (int j = 0; j < indice - 1 - i; j++) {
				if (copia[j]->getCursosRealizados() > copia[j + 1]->getCursosRealizados()) {
					Instructor* temp = copia[j];
					copia[j] = copia[j + 1];
					copia[j + 1] = temp;
				}
			}
		}

		cout << endl << "Instructores ordenados por cursos realizados:" << endl;
		for (int i = 0; i < indice; i++) {
			cout << endl;
			copia[i]->mostrar();
		}
		delete[] copia;
	}

	
	void mostrarConMasCursos() {
		if (indice == 0) {
			cout << "No hay instructores registrados." << endl;
			return;
		}
		int iMax = 0;
		for (int i = 1; i < indice; i++) {
			if (instructores[i]->getCursosRealizados() > instructores[iMax]->getCursosRealizados())
				iMax = i;
		}
		cout << endl << "Instructor con mayor cantidad de cursos realizados" << endl;
		instructores[iMax]->mostrar();
	}
};