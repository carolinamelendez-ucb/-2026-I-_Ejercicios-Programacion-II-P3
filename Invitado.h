#pragma once
#include <iostream>
#include <string>
using namespace std;

class Invitado {
private:
	string nombre;
	string telefono;
public:

	Invitado() = default;

	Invitado(string nombre, string telefono) {
		this->nombre = nombre;
		this->telefono = telefono;
	}

	void mostrar() {
		cout << "Nombre del Invitado es: " << nombre << endl;
		cout << "Telefono del Invitado es: " << telefono << endl;
	}


};