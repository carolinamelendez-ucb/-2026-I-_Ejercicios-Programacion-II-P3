#pragma once
#include <iostream>
#include <string>
#include "Libro.h"
using namespace std;

class Estudiante {
private:
	int ci;
	string nombre;
	Libro* libroAsignado;
public:

	Estudiante(int ci, const string& nombre, Libro* libroAsignado)
		: ci(ci), nombre(nombre), libroAsignado(libroAsignado)
	{
	}
	int getCi() {
		return ci;
	}
};