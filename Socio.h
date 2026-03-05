#pragma once
#include <iostream>

using namespace std;

class Socio {
private:
	int ci;
	string nombre;
	int telf;
public:
	Socio() {
		this->ci = 0;
		this->nombre = "";
		this->telf = 0;
	}
	Socio(int ci, string nombre, int telf) {
		this->ci = ci;
		this->nombre = nombre;
		this->telf = telf;
	}
	void mostrar() {
		cout << "Ci: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telf << endl;
	}

	string getNombre(){ return nombre; }
};