#pragma once
#include "Estudiante.h"

class Postgrado : public Estudiante {
private:
	float porcentajeRecargo;
public:
	Postgrado(int ci, string nombre, int matricula)
		:Estudiante(ci, nombre, matricula) {
		this->porcentajeRecargo = 0.2;
	}
	float calcularPago() override {
		return matricula + (matricula * porcentajeRecargo);
	}
};
