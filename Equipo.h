#pragma once
#include<iostream>
#include<string>
#include "Socio.h"
using namespace std;

class Equipo {
	Socio piloto;
	Socio copiloto;
	string nombreEquipo;
	string autoConQueCompetiran;

private:
public:
	
	Equipo(Socio piloto, Socio copiloto, string nombreEquipo, string autoConQueCompetiran) {
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreEquipo = nombreEquipo;
		this->autoConQueCompetiran = autoConQueCompetiran;
	}
	Socio getCopiloto() {
		return copiloto;
	}
	Socio getPiloto() {
		return piloto;
	}
	void mostrar() {
		cout << endl;
		cout << "El nombre del Equipo es: " << nombreEquipo << endl;
		cout << "El auto con el que vorrerarn es: " << autoConQueCompetiran << endl;
		cout << "El piloto es: "<<endl;
		piloto.mostrar();
		cout << "El copiloto es :  " <<endl;
		copiloto.mostrar();
		
	}
	
};