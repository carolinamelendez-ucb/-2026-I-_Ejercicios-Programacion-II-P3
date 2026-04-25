#pragma once
#include <iostream>
#include <string>

using namespace std;
class Pelicula
{
private:
	string nombre;
	float duracion;
public:
	Pelicula(const string& nombre, float duracion)
		: nombre(nombre), duracion(duracion)
	{
	}
	void mostrar() {
		cout << "Nomre de la peli: " << nombre << endl;
		cout << "Duracion: " << duracion << endl;
	}
};

