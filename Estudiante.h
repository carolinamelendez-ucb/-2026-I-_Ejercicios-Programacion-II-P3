#pragma once
#include "Libro.h"

class Estudiante {
private:
	int ci;
	string nombre;
	Libro* libroAsignado;
public:
	Estudiante(int ci, string nombre) :ci(ci), nombre(nombre), libroAsignado(nullptr) {

	}

	void asignarLibro(Libro* libro) {
		this->libroAsignado = libro;
	}

	int getCi() { return ci; }
};