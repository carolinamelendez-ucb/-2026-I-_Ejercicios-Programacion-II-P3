#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"

using namespace std;
class VectorEstudiante {
private:
	int tamanio;
	int indice;
	Estudiante** estudiantes;
public:

	VectorEstudiante() = default;

	VectorEstudiante(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->estudiantes = new Estudiante * [tamanio];
	}
	void agregar(Estudiante* nuevoEstudiante) {
		if (indice < tamanio) {
			estudiantes[indice] = nuevoEstudiante;
			indice++;
		}
		else {
			cout << "No es posible registrar al Estudiante, Error" << endl;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			estudiantes[i]->mostrar();
		}
	}

	bool BuscarEstudiante(int ci) {
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getCi() == ci) {
				return true;
			}
		}
		return false;
	}

	void buscarEstudiantes5prestamos() {
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getCantidadLibrosPrestadosActivos() ==5) {
				estudiantes[i]->mostrar();
			}
		}
	}

	Estudiante* getEstudiante(int ci) {
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getCi() == ci) {
				return estudiantes[i];
			}
		}
		return nullptr;
	}


	~VectorEstudiante() {
		for (int i = 0; i < indice; i++) {
			delete estudiantes[i];
		}
		delete[] estudiantes;
	}
	

};