#pragma once
#include <iostream>
using namespace std;

class Estudiante {
private:
	string nombre;
	string correo;
public:


	Estudiante() = default;

	Estudiante(const string& nombre, const string& correo)
		: nombre(nombre), correo(correo)
	{
	}
};