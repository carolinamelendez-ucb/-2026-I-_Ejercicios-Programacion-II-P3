#pragma once
#include <string>
#include <iostream>
#include "vecLibro.h"
using namespace std;
class Estudiante {
private: 
	VecLibro* libro;
	int ci;
	string nombre;
public:
	Estudiante(int ci, string nombre) {
		this->ci = ci;
		this->nombre = nombre;
		this->libro = nullptr;
	}
	void asignarLibro(Libro* nuevo) {
		libro->agregar(nuevo);
	}
	void mostrar() {
		cout << "Nombre del estudiante: " << nombre << endl;
		libro->mostrar();
	}
};