#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class TrasnporteTerrestre : public Transporte {
public:
	TrasnporteTerrestre(const string& nom,const string& tp)
	:Transporte(nom,tp){
	}

	double calcularCosto(double distancia) override {
		double recargo = 0;
		if (distancia > 100) {
			recargo = 0.10;
		}
		return distancia * 0.5 * (1 + recargo);
	}

	void mostrarInfo(){
		cout<<"Transporte: "<<nombre<<" ("<<tipo<<")"<< endl;
	}

};