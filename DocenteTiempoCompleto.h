#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
using namespace std;

class DocenteTiempoCompleto : public Docente {
private:
	int aniosAntiguedad;
public:
	DocenteTiempoCompleto(int ci, const string& nombre, int salario, int aniosAntiguedad, bool finalizo)
	{
		float bono = 0;
		if (aniosAntiguedad >= 0 && aniosAntiguedad <= 5) {
			bono = 0.05;
		}
		else if (aniosAntiguedad >= 6 && aniosAntiguedad <= 10) {
			bono = 0.15;
		}
		else if (aniosAntiguedad > 10) {
			bono = 0.25;
		}
		this->ci = ci;
		this->nombre = nombre;
		this->bono = bono;
		this->salario = salario;
		this->aniosAntiguedad = aniosAntiguedad;
		this->tipo = "Tiempo Completo";
		this->finalizoSeleccion = finalizo;
	}

	void mostrar() {
		Docente::mostrar();
		cout << "Anios de antiguedad: " << aniosAntiguedad << endl;
	}
};