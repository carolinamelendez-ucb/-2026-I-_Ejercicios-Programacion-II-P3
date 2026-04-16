#pragma once
#include "Estudiante.h"

class Postgrado : public Estudiante {
private:
	double porcentajeRecargo;

public:
	Postgrado(string ci, string nombre, float matricula) :
		Estudiante(ci, nombre, matricula) {
		this->porcentajeRecargo = 0.2;
	}
	double calcularRecargo() {
		return matricula * porcentajeRecargo;
	}
	double calcularMatricula() {
		return matricula + calcularRecargo();
	}
	
	void mostrar() {
		Estudiante::mostrar();
		cout << "Recargo: " << calcularRecargo() << endl;

	}

};
