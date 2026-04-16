#pragma once

#include "Persona.h"
#include "VectorCursos.h"
const int maxCursos = 5;
class Estudiante : public Persona {
protected:
	double matricula;
	bool estadoPago;

public:
	Estudiante(string ciEstudiante, string nombreEstudiante, double matricula) :
		Persona(ciEstudiante, nombreEstudiante) {
		this->matricula = matricula;
		this->estadoPago = true;
	}
	bool realizoPagoMatricula() {
		return estadoPago;
	}

	virtual double calcularMatricula() = 0;

	virtual void mostrar() {
		Persona::mostrar();
		cout << "Matricula total: " << calcularMatricula() << endl;
	}
	
};