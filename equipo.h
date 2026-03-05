#pragma once
#include <iostream>
#include <string>
#include "socio.h"
using namespace std;

class Equipo {
private: 
	Socio* piloto;
	Socio* copiloto;
public:
	Equipo(Socio* piloto, Socio* copiloto) {
		this->piloto = piloto;
		this->copiloto = copiloto;
	}
	void mostrar() {
		cout << "--- Piloto ----" << endl;
		piloto->mostrar();
		cout << "--- Copiloto ----" << endl;
		copiloto->mostrar();
	}
};
