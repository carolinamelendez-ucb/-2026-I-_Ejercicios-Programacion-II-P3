#pragma once
#include "Docente.h"

class TiempoCompleto : public Docente {
private:
	int aniosAntiguedad;

public:
	TiempoCompleto(string ci, string nombre, int aniosAntiguedad) :
		Docente(ci, nombre, 0.05, 3000) {

		this->aniosAntiguedad = aniosAntiguedad;
	}

	double calcularBono() {
		if (aniosAntiguedad >= 0 && aniosAntiguedad <= 5) {
			return salarioBase * porcentajeBono;
		}
		else if (aniosAntiguedad >= 6 && aniosAntiguedad <= 10) {
			porcentajeBono = 0.15;
			return salarioBase * porcentajeBono;
		}
		else {
			porcentajeBono = 0.25;
			return salarioBase * porcentajeBono;
		}
	}

	double calcularSalario() {
		return salarioBase + calcularBono();
	}

	void mostrar() {
		Docente::mostrar();
		cout << "Anios de antiguedad: " << aniosAntiguedad << endl;
		cout << "Bono: " << calcularBono() << endl;
	}
};