#pragma once

#include <iostream>
#include <string>
using namespace std;
class Pelicula {
private:
	string nombre;
	string codigo;
public:
	Pelicula(string nombre, string codigo) {
		this->nombre = nombre;
		this->codigo = codigo;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " <<codigo<< endl;
	}
};