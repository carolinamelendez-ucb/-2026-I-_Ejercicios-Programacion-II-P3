#pragma once
#include <iostream>
#include <string>

using namespace std;
class Socio
{
private:
	string nombre;
	int ci;
	string tipo;
public:
	Socio(string nombre, int ci,string tipo) {
		this->ci = ci;
		this->nombre = nombre;
		this->tipo = tipo;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "CI: " << ci << endl;
		cout << "Tipo: " << tipo << endl;
	}
	int getCI() {
		return ci;
	}
	string getNombre() {
		return nombre;
	}
	string getTipo() {
		return tipo;
	}
};

