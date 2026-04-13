#pragma once
#include "Docente.h"

class MedioTiempo : public Docente {
private:
	int cantCursos;
public:
	MedioTiempo(int ci, string nombre, float salario)
		: Docente(ci, nombre, salario) {
		this->cantCursos = 0;
	}
	int getCantCursos() {
		return cantCursos;
	}
	float calcularSalario() override {
		if (cantCursos >= 2) {
			return salario + (salario * 0.1);
		}
		else {
			return salario;
		}
	}
};

