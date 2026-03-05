#pragma once
#include <iostream>
#include <string>
#include "Socio.h"
using namespace std;

class Equipo
{
private:
	Socio* piloto;
	Socio* copiloto;
	string nombre_equipo;
	string carro;
public:
	Equipo(Socio* piloto, Socio* copiloto, string nombre_equipo, string carro)
	{
		this->piloto = piloto;
		this->copiloto = copiloto;
		this->nombre_equipo = nombre_equipo;
		this->carro = carro;
	}
	void mostrar()
	{
		cout << "Piloto: " << endl;
		piloto->mostrar();
		cout << "Copiloto: " << endl;
		copiloto->mostrar();
		cout << "Nombre del Equipo: " << nombre_equipo << endl;
		cout << "Carro: " << carro << endl;
	}
};