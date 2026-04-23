#pragma once
#include <iostream>
#include <string>
#include <exception>            
#include "Libro.h"
using namespace std;


class Estudiante {
private:
	int ci;
	string nombre;
	Libro* libroAsig;
public:
	Estudiante(int ci, const string& nombre, Libro* libroAsig)
		: ci(ci), nombre(nombre), libroAsig(libroAsig)
	{}

	int getCi() {
		return ci;
	}

	Libro* getLibro() {
		return libroAsig;
	}

	void mostrarEstu() {
		cout << "CI: "<<ci << endl;
		cout << "Nombre: "<<nombre << endl;
		cout << "Libro Asignado: "<<libroAsig << endl;
	}


};