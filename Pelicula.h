#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pelicula {
private:
	string nombre;
	int duracion;
public:
	Pelicula(const string& nombre, int duracion)
		: nombre(nombre), duracion(duracion)
	{
	}
	void mostrar() {
		cout << "Nombre de la pelicula: " << nombre << endl;
		cout << "Duacion: " << duracion << endl;
	}
};