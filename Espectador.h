#pragma once
#include <iostream>
#include <string>
using namespace std;

class Espectador {
private:
	string nombre;
	int telefono;
public:
	Espectador(){}
	Espectador(const string& nombre, int telefono)
		: nombre(nombre), telefono(telefono)
	{
	}
};
