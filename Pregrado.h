#pragma once
#include "Estudiante.h"

class Pregrado : public Estudiante {
public:
	Pregrado(int ci, string nombre)
		:Estudiante(ci, nombre, 2000) {

	}
	float calcularPago() override {
		return matricula;
	}
};