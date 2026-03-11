#pragma once
#include <iostream>
#include <string>
#include "socio.h"
using namespace std;
class Equipo {
private:
	string nomEquipo;
	string autoComp;
	Socio* piloto;
	Socio* copiloto;
public:
	Equipo(string nomEquipo, string autoComp, Socio* piloto, Socio* copiloto) {
		this->nomEquipo = nomEquipo;
		this->autoComp = autoComp;
		this->piloto = piloto;
		this->copiloto = copiloto;
	}
	Socio* getPiloto() {
		return piloto;
	}
	Socio* getCopiloto() {
		return copiloto;
	}
	void mostrarEquipo() {
		cout << "Equipo: " << nomEquipo << endl;
		cout << "Auto: " << autoComp << endl;
		cout << "Piloto: " << endl;
		piloto->mostrarSocio();
		cout << "Copiloto" << endl;
		copiloto->mostrarSocio();
	}
};