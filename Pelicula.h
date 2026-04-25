#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pelicula {
private:
	string nombre;
	string descripcion;
public:
	Pelicula(const string& nombre, const string& descripcion)
		: nombre(nombre), descripcion(descripcion)
	{
	}

	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Descripcion: " << descripcion << endl;
	}
};