#pragma once
#include<iostream>
#include <string>
using namespace std;

class Proyecto {
protected:
	string nombre;
	int codigo;
public:
	Proyecto() = default;

	Proyecto(const string& nombre, int codigo)
		: nombre(nombre), codigo(codigo)
	{
	}

	virtual float calcularCosto() = 0;

	virtual void mostrarInformacion() {
		cout << "Nombre del proyecto: " << nombre << endl;
		cout << "Codigo: " << codigo << endl;
	}

	int getCodigo() {
		return codigo;
	}

	
};