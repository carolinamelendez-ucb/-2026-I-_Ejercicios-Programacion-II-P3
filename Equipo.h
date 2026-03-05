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
	string autoEquipo;
public:
	Equipo(Socio piloto, Socio copiloto, string nombreEquipo, string autoEquipo) {
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreEquipo = nombreEquipo;
		this->autoEquipo = autoEquipo;
	}
	void mostrar() {
		cout << "Piloto: ";
		piloto.mostrar();
		cout << "Copiloto: ";
		copiloto.mostrar();
		cout << "Nombre del Equipo: " << nombreEquipo << endl;
		cout << "Auto con el que competiran: " << autoEquipo << endl;
	}
	string getNombrePiloto() { return piloto.getNombre(); }
	string getNombreCopiloto() { return copiloto.getNombre(); }
	string getNombreEquipo() { return nombreEquipo; }
};