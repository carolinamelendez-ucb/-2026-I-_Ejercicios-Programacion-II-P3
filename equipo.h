#pragma once
#include <iostream>
#include <string>
using namespace std;
class Equipo {
private:
	string tipo;
	string nombreEquipo;
	string autoCom;
public:
	Equipo(string tipo, string nombreEquipo, string autoCom) {
		this->tipo = tipo;
		this->nombreEquipo = nombreEquipo;
		this->autoCom = autoCom;
	}
	void mostrarEquipo() {
		cout << "Tipo de formacion: " << tipo << endl;
		cout << "Nombre del Equipo: " << nombreEquipo << endl;
		cout << "Auto en el que competiran: " << autoCom << endl;
	}
};