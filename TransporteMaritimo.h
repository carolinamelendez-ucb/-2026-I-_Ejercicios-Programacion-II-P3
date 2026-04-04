#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class TransporteMaritimo : public Transporte {
public:
	TransporteMaritimo(const string& nom, const string& tp)
		:Transporte(nom,tp) {
	}

	double calcularCosto(double distancia){
		double recargoFijo = 0;
		if (distancia > 500) {
			recargoFijo = 50;
		}
		return distancia * (1.2 + recargoFijo);
	}

	void mostrarInfo() {
		cout<<"Transporte: "<<nombre<<" ("<<tipo<<")" << endl;
	}
};