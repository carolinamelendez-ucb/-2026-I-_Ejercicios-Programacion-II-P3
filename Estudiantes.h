#pragma once
#include <iostream>
#include <string>
#include "Libro.h"
class Estudiantes
{
private:
	int ci;
	string nombre;
	Libro* libroAsignado;



public:

	Estudiantes(int ci, const string& nombre, Libro* libroAsignado)
		: ci(ci), nombre(nombre)
	{
		this->libroAsignado = nullptr;
	}
	int getCi()
	{
		return ci;
	}
};

