#pragma once
#include <iostream>
#include <string>
#include "Socio.h"

using namespace std;
class Equipo
{
private:
	string nombreEquipo;
	int codigo;
	Socio* socio;
public:
	Equipo(string nombreEquipo, int codigo) {
		this->codigo;
		this->nombreEquipo;
	}
	void mostrar() {
		cout << "Nombre: " << nombreEquipo << endl;
		cout << "Codigo: " << codigo << endl;
	}
	int getCodgio() {
		return codigo;
	}
	string getNombreEquipo() {
		return nombreEquipo;
	}
};

