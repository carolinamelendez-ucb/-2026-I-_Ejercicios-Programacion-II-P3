#pragma once
#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
	string placa;
	string modelo;
	string marca;
public:
	Auto(const string& placa, const string& modelo, const string& marca)
		: placa(placa), modelo(modelo), marca(marca)
	{
	}
	void mostrar() {
		cout << placa << " - " << modelo << " - " << marca << " - " << endl;
	}
};

