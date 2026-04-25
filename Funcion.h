#pragma once
#include <iostream>
#include <string>
using namespace std;

class Funcion {
private:
	double horaFuncion;
	bool disponible;
public:
	Funcion(double horaFuncion, bool disponible)
		: horaFuncion(horaFuncion), disponible(disponible)
	{}

	void mostrar() {
		cout << "Hora:"<<horaFuncion << endl;
		if (disponible) {
			cout << "Funcion Disponible" << endl;
		}
		else {
			cout << "Funcion No Disponible" << endl;
		}
	}

	bool getDispo() {
		return disponible;
	}

	void cambiarNoDispo() {
		this->disponible = false;
	}

	~Funcion(){}
};