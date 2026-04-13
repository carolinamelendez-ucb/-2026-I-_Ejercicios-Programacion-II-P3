#pragma once
#include "Persona.h"

class Docente : public Persona {
protected:
	float salario;
	bool aprobado;
public:
	Docente(int ci, string nombre, float salario)
		: Persona(ci, nombre) {
		this->salario = salario;
		this->aprobado = false;

	}
	void aprobar() {
		aprobado = true;
	}
	bool estaAprobado() {
		return aprobado;
	}
	virtual float calcularSalario() {
		return salario;
	}
};
