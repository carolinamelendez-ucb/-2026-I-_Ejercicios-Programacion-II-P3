#pragma once
#include <iostream>
#include <string>
#include "Socios.h"
using namespace std;

class Equipo
{
private:
	Socio piloto;
	Socio copiloto;
	string nombreEquipo;
	string autoC;
public:
	
	Equipo(Socio piloto, Socio copiloto, string nombreEquipo, string autoC)
	{
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombreEquipo = nombreEquipo;
		this->autoC = autoC;
	}
	void mostrar()
	{

		cout << "Piloto: "  << endl;
		piloto.mostrar();
		cout << "copiloto: " << endl;
		copiloto.mostrar();
		cout << "nombre del equipo: " << nombreEquipo << endl;
		cout << "Tipo de auto" << autoC << endl;
	}
	Socio getPiloto()
	{
		return piloto;
	}
	Socio getCopiloto()
	{
		return copiloto;
	}


};
