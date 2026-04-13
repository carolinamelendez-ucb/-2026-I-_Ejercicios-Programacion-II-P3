#pragma once
#include "Persona.h"

class Estudiante : public Persona {
protected:
	float matricula;
	bool pago;
public:
	Estudiante (int ci, string nombre, float matricula)
		: Persona(ci, nombre) {
		this->matricula = matricula;
		this->pago = false;
	}
	void pagar() {
		pago = true;
	}
	bool pagoRealizado() {
		return pago;
	}
	virtual float calcularPago() {
		return matricula;
	}
};

