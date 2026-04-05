#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class Operador {
private:
	int ci;
	string nombre;
	int distancia;
	Transporte* transporte;

public:
	Operador() = default;
	
	Operador(int ci, const string& nombre, int distancia)
		: ci(ci), nombre(nombre), distancia(distancia)
	{
		this->transporte= nullptr;
	}

	void asignarTransporte(Transporte* transporte) {
		this->transporte = transporte;
	}

	double calcularCostoGenerado() {
		if (transporte == nullptr) {
			return 0;
		}
		return transporte->calcularCosto(distancia);
	}

	void mostrar() {
		cout << "CI del Operador: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Distancia: " << distancia << endl;

		if (transporte != nullptr) {
			transporte->mostrar();
			cout << "Costo generado: " << calcularCostoGenerado() << endl;
		}
		else {
			cout << "No se tiene transporte asignado" << endl;
		}
	}

	int getCi() {
		return ci;
	}

	int getDistancia() {
		return distancia;
	}
	
};