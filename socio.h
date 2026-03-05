#pragma once
#include <iostream>
#include <string>
using namespace std;
class Socio {
private:
	int ci;
	string nombre;
	int telefono;
public:
	Socio(int ci, string nombre, int telefono) {
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
	}
	void mostrarSocio() {
		cout << "CI: " << ci << endl;
		cout << "Nombre del Socio: " << nombre << endl;
		cout << "Telefono del Socio: " << telefono << endl;
	}
};
