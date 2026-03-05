#pragma once
#include <iostream>
#include <string>
using namespace std;

class Socio {
private:
	string nombre;
	int edad;
public:
	Socio(string nombre, int edad) {
		this->nombre = nombre;
		this->edad = edad;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
	}
};
	





