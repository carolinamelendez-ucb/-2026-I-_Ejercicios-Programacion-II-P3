#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
	int ci;
	string nombre;
public:
	Cliente(int ci, const string& nombre)
		: ci(ci), nombre(nombre)
	{
	}
	void mostrar() {
		cout << "Ci: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
	}
};