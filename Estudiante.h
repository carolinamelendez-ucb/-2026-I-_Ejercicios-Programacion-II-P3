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
	Estudiante(int ci, const string& nombre)
		: ci(ci), nombre(nombre)
	{
		this->libroAsignado = nullptr;
	}

	int getCi() { return ci; }

	int getCodigoLibro() { return libroAsignado->getCodigo(); }

	void asignarLibro(Libro* libro) {
		libroAsignado = libro;
		libroAsignado->aumentarPrestamo();
	}

	void mostrar() {
		cout << "Ci: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
	}
};