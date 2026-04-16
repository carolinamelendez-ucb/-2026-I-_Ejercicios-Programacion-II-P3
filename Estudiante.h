#pragma once

#include "Persona.h"
#include "VectorCursos.h"
const int maxCursos = 5;
class Estudiante : public Persona {
protected:
	int matricula;
	bool estadoPago;

public:
	Estudiante(string ciEstudiante, string nombreEstudiante, float matricula) :
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