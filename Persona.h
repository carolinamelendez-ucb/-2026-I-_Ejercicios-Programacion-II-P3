#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
	int ci;
	string nombre;
public: 
	Persona(int ci, const string& nombre)
		: ci(ci), nombre(nombre)
	{
	}
	void mostrar() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
	}
	int getCI() {
		return ci;
	}
};
