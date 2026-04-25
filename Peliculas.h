#pragma once
#include <iostream>
#include <string>
using namespace std;
class Peliculas
{
private:
	string nombre;
	string descripcion;
public:


	Peliculas(const string& nombre, const string& descripcion)
		: nombre(nombre), descripcion(descripcion)
	{
	}
};

