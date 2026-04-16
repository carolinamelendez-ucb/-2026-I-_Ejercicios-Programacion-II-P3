#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
	string nombre;
	int ci;
	string tipo;
	int total;
public:
	Persona(const string& nombre, int ci , string tipo)
		: nombre(nombre), ci(ci) , tipo(tipo)
	{
		this->total = 0;
	}

	int getCi(){
		return ci;
	}

	int getTotal() {
		return total;
	}
	virtual void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
		cout << "tipo: " << tipo << endl;

	}
};