#pragma once
#include <iostream>
#include <string>

using namespace std;


class Cliente
{
private:
	string nombre;
	int ci;
public:
	Cliente(const string& nombre, int ci)
		: nombre(nombre), ci(ci)
	{}
	void mostrar()
	{
		cout << "nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
	}
	
};

