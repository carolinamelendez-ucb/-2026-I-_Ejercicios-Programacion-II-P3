#pragma once
#include "Estudiante.h"

class Postgrado : public Estudiante {
private:
	float recargo;
public:
	Postgrado(string nombre, int ci, int matricula, bool estado) : Estudiante(nombre, ci, "Postgrado", matricula,estado) {
		this->recargo = 0.20;
	}
	void mostrar() {
		Estudiante::mostrar();
		cout << "Recargo " << recargo * 100 << "%" << endl;
	}

	int getRecargo() {
		return matricula * recargo;
	}

	void calcularTotal() {
		total = matricula + getRecargo();
	}
};