#pragma once
#include <string>
#include <iostream>

using namespace std;

class Alumno {
private:
	string nombre;
	int edad;
public:
	Alumno(string nombre, int edad) {
		this->nombre = nombre;
		this->edad = edad;
	}

	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
	}
	void setNombre(string nuevoNombre) {
		this->nombre = nuevoNombre;
	}
};
