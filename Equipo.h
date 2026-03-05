#pragma once
#include <iostream>
#include <string>
using namespace std;

class Equipo {
private:
	string tipo;
	int numero;
public:
	Equipo(string tipo, int numero)
	{
		this->tipo = tipo;
		this->numero = numero;
	}
	void mostrar() {
		cout << "tipo: " << tipo << endl;
		cout << "numero: " << numero << endl;
	}
};



