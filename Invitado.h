#pragma once
#include <iostream>
#include <string>
#include <random>
using namespace std;


class Invitado
{
private:
	string nombre;
	int telefono;
public:

	Invitado(const string& nombre, int telefono)
		: nombre(nombre), telefono(telefono)
	{
	}
	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telefono << endl;

	}
};
