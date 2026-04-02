#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"
using namespace std;

class ProyectoInterno : public Proyecto {
private:
	int horasTrabajo;
	float costoHoras;
public:
	ProyectoInterno(int codigo, string nombre, int horasTrabajo, float costoHoras)
		: Proyecto(nombre, codigo) {
		this->horasTrabajo = horasTrabajo;
		this->costoHoras = costoHoras;
	}
	float calcularCosto() {
		if (horasTrabajo > 8) {
			//Si el proyecto toma mas de 8 horas se incmenta 50 bs al total
			return (horasTrabajo * costoHoras) + 50;

		}
		else {
			return (horasTrabajo * costoHoras);
		}
	}

	void mostrarInformacion() {
		Proyecto::mostrarInformacion();
		cout << "Costo del Proyecto Interno: " << calcularCosto() << endl;
	}


};