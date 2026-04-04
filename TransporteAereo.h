#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class TransporteAereo:public Transporte {
public:
	TransporteAereo(const string&nom,const string&tp)
	:Transporte(nom,tp){
	}

	double calcularCosto(double distancia) {
		double descuento = 0;
		if (distancia > 1000) {
			descuento = 0.15;
		}
		return distancia * 2.0 * (1 - descuento);
	}

	void mostrarInfo(){
		cout << "Transporte: " << nombre << " ("<<tipo<<")"<< endl;
	}
};