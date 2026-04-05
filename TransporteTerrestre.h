#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;
class TransporteTerrestre: public Transporte{
public:
	TransporteTerrestre(int numPLaca, float costoBase)
	:Transporte(numPLaca, costoBase){

	}

	double calcularCosto(int distancia) {
		return distancia * costoBase * (1 + 0.10 * (distancia > 100));
	}
	void mostrar() {
		cout << "Transporte Terrestre" << endl;
		Transporte::mostrar();
	}
};