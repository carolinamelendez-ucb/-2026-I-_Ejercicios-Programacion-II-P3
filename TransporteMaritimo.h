#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;
class TransporteMaritimo : public Transporte {
	public:
		TransporteMaritimo(int numPLaca, float costoBase)
			:Transporte(numPLaca, costoBase) {

		}

		double calcularCosto(int distancia) {
			return distancia * costoBase + 50 * (distancia > 500);
		}
		void mostrar() {
			cout << "Transporte Maritimo" << endl;
			Transporte::mostrar();
		}
};