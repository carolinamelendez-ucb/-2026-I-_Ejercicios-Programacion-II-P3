#pragma once
#include <iostream>
#include <string>
using namespace std;
class Cliente {
private:
	int id;
	string nombre;

public:

	Cliente() = default;

	Cliente(int id, const string& nombre)
		: id(id), nombre(nombre)
	{
	}
	void mostrar() {
		cout << "Nombre del Cliente: " << nombre << endl;
		cout << "Id del Cliente: " << id << endl;
	}
};