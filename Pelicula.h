#pragma once
#include <iostream>
#include <string>
#include "Funcion.h"
using namespace std;

class Pelicula {
private:
	string nombre;
	Funcion* infoPeli;
public:
	Pelicula(const string& nombre,double hora,bool dispo)
		: nombre(nombre),infoPeli()
	{}

	Funcion* getFuncion() {
		return infoPeli;
	}

	void mostrar() {
		cout << "Pelicula:"<<nombre << endl;
		infoPeli->mostrar();
	}


	~Pelicula() {
		delete infoPeli;
	}

};