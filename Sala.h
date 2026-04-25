#pragma once

#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;
class Sala {
private:
	string nombre;
	string codigo;
	int numFilas;
	int numColumnas;
	Funcion* funcion;
	
public:
	Sala(string nombre, string codigo, int numFilas, int numColumnas) {
		this->nombre = nombre;
		this->codigo = codigo;
		this->numFilas = numFilas;
		this->numColumnas = numColumnas;
		this->funcion = nullptr;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " <<codigo<< endl;
		cout << "Num filas: " << numFilas << endl;
		cout << "Num Columnas: " << numColumnas << endl;
		cout << "Funcion:" << endl; 
		funcion->mostrar();

	}
};