#pragma once
#include <iostream>

using namespace std;

class Auto {
private:
	string placa;
	string modelo;
	int puertas;
public:
	Auto(const string& placa, const string& modelo, int puertas)
		: placa(placa), modelo(modelo), puertas(puertas)
	{
	}

	void mostrar() {
		cout << "Placa: " << placa << endl;
		cout << "Modelo: " << modelo << endl;
		cout << "Puertas: " << puertas << endl;
	}
};