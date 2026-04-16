
#pragma once
#include "Estudiante.h"

class Pregrado : public Estudiante {

public:
	Pregrado(string nombre, int ci, bool estado) : Estudiante(nombre, ci, "Pregrado", 2000,estado) {

	}
	void mostrar() {
		Estudiante::mostrar();

	}

	void calcularTotal() {
		total = matricula;
	}
};