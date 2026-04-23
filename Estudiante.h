#pragma once
#include "Libro.h"

class Estudiante {
private:
	int ci;
	string nombre;
	Libro* libroAsignado;
public:
	Estudiante(int ci, string nombre, Libro* libroAsignado) {
		this->ci = ci;
		this->nombre = nombre;
		this->libroAsignado = nullptr;
	}
};