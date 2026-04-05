#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;
class TransporteAereo: public Transporte {
public:
	TransporteAereo(int numPLaca, float costoBase)
		:Transporte(numPLaca, costoBase) {

	}

	double calcularCosto(int distancia) {
		return distancia * costoBase * (1 - 0.15 * (distancia > 1000));
	}
	void mostrar() {
		cout << "Transporte Aereo" << endl;
		Transporte::mostrar();
	}
};