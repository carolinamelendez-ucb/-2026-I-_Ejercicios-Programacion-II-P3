#pragma once
#include "Libro.h"

class Estudiante {
private:
	int ci;
	string nombre;
	Libro* libroAsignado;
public:
	Estudiante(int ci, string nombre) {
		this->ci = ci;
		this->nombre = nombre;
		this->libroAsignado = nullptr;
	}
	int getCI() {
		return ci;
	}
	void asignarLibro(Libro* libro) {
		libroAsignado = libro;
	}
};