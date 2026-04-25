#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
	string nombre;
	int boleto;
public:
	Cliente(const string& nombre, int boleto)
		: nombre(nombre), boleto(boleto)
	{}

	void mostrar() {
		cout << "Nombre:" << nombre << endl;
		cout << "Num. Boleto:" << boleto << endl;
	}

	~Cliente(){}
};