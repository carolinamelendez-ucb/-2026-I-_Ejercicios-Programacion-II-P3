#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona {
protected:
	string ci;
	string nombre;
public:
	Persona(string ci, string nombre) {
		this->ci = ci;
		this->nombre = nombre;

	}

	virtual void mostrar() {
		cout << "CI: " << this->ci << endl;
		cout << "Nombre: " << this->nombre << endl;
	}

	string getCi() {
		return ci;
	}

};