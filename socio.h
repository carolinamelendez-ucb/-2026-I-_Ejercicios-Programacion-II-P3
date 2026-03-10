#pragma once
#include <iostream>
#include <string>
using namespace std;

class Socio {
private:
	int ci;
	string nombre;
	int telf;
public:
	Socio(int ci, string nombre, int telf) {
		this->ci = ci;
		this->nombre = nombre;
		this->telf = telf;
	}
	string getNombre() {
		return nombre;
	}
	void mostrar() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telf << endl;
	}
};
