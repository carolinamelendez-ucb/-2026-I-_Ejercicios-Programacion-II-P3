#pragma once
#include "Docente.h"

class MedioTiempo : public Docente {
public:
	MedioTiempo(string ci, string nombre) :
		Docente(ci, nombre, 0.1, 1500) {

	}
	double calcularSalario() {
		return salarioBase + (salarioBase * porcentajeBono);
	}
};