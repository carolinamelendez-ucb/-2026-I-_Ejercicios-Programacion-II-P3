#pragma once
#include <iostream>
#include<string>
#include"Transporte.h"
using namespace std;
class Operador {
private:
	string nombre;
	int ci;
	float distancia;
	Transporte* transporte;
public:
	Operador(const string& nombre, int ci)
		: nombre(nombre), ci(ci), distancia(0), transporte(nullptr)
	{
	}
	int getCi(){
		return ci;
	}
	void asignarTransporte(Transporte* t,float d){
		transporte = t;
		distancia = d;
	}
	float calcularCosto() {
		if (transporte == nullptr)return 0;
		return transporte->calcularCosto(distancia);
	}
	void mostrar() {
		cout << nombre << " | CI: " << ci << endl;
		if (transporte != nullptr) {
			transporte->mostrar();
			cout << "Distancia: " << distancia << endl;
			cout<< " | Costo: " << calcularCosto() << endl;
		}
		else {
		cout << "Sin transporte asignado\n";
		}
		cout << "-------------------\n";
		
	}
};