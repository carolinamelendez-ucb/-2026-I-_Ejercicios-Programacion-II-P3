#pragma once
#include <iostream>
#include <string>
#include "socios.h"
using namespace std;
class Equipo {
private:
	Socio piloto;
	Socio copiloto;
	string nombreequipo;
	string autocomp;
public:
	Equipo(Socio piloto, Socio copiloto, string nombreequipo, string autocomp) {
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreequipo = nombreequipo;
		this->autocomp = autocomp;
	}
	string getnompiloto() { return piloto.getnombre(); }
	string getnomcopiloto() { return copiloto.getnombre(); }
	void mostrar() {
		cout << "nombre piloto: " << piloto.getnombre() << endl;
		cout << "nombre copiloto: " << copiloto.getnombre() << endl;
		cout << "nombre equipo: " << nombreequipo << endl;
		cout << "autocomp: " << autocomp << endl;
	}
};

