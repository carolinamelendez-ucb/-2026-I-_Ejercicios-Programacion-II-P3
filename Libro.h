#pragma once
#include <iostream>
#include <string>

using namespace std;
class Libro {
private: 
	int codigo;
	string titulo;
	bool estado;
public:

	Libro() = default;
	Libro(int codigo, const string& titulo)
		: codigo(codigo), titulo(titulo)
	{
		this->estado = true;
	}
	
	void mostrar() {
		cout << "Codigo del libro: " << codigo<<endl;
		cout << "Nombre del libro: " << titulo<<endl;
		if (estado) {
			cout << "Estado del libro: Disponible" << endl;
		}
		else {
			cout << "Estado del libro: NO disponible" << endl;
		}
	}
	int getCodigo() {
		return codigo;
	}
	bool getDisponible() {
		return estado;
	}

	void estadoNiDisponible() {
		estado = false;
	}
	void estadoDisponible() {
		estado = true;
	}


};