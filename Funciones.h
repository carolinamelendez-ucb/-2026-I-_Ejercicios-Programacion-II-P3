#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "ArrayGenerico.h"
#include "Cliente.h"
using namespace std;
class Funcion {
private:
	string nombre;
	string codigo;
	int capacidad;
	Pelicula* pelicula;
	ArrayGenerico<Cliente>* arrayClientes;

public:
	Funcion(string nombre, string codigo, int capacidad) {
		this->nombre = nombre;
		this->codigo = codigo;
		this->capacidad = capacidad;
		this->pelicula = nullptr;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " <<codigo<< endl;
		cout << "Capacidad: " << capacidad<<endl;
		cout << "Pelicula: " << endl;
		pelicula->mostrar();
		cout << "Clientes: " << endl;
		arrayClientes->mostrar();
	}
};