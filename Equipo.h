#pragma once
#include <iostream>
#include <string>
#include "Socio.h"
using namespace std;
class Equipo {
private:
	Socio piloto;
	Socio copiloto;
	string nombreEquipo;
	string autom;
public:
	Equipo(Socio piloto, Socio copiloto, string nombreEquipo, string autom) {
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreEquipo = nombreEquipo;
		this->autom = autom;
	}
	
	
	void mostrarEquipo() {
		cout << "Equipo: " << nombreEquipo << endl;
		cout << "Auto: " << autom << endl;

		cout << "Piloto:" << endl;
		piloto.mostrarSocio();

		cout << "Copiloto:" << endl;
		copiloto.mostrarSocio();
	}
};

