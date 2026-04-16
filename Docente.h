#pragma once
#include "Persona.h"

class Docente : public Persona {
protected:
	float porcentajeBono;
	bool estado;
	double salarioBase;
public:
	Docente(string ciDocente, string nombreDocente, float porcentajeBono, double salarioBase) :
		Persona(ciDocente, nombreDocente) {
		this->porcentajeBono = porcentajeBono;
		this->estado = true;
		this->salarioBase = salarioBase;
	}

	bool aproboEntrevista() {
		return estado;
	}

	virtual double calcularSalario() = 0;

	virtual void mostrar() {
		Persona::mostrar();
		cout << "Salario total: " << calcularSalario() << endl;
	}
};