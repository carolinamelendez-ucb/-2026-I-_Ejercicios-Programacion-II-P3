#pragma once
#include <string>
#include <iostream>

using namespace std;

class Espectador
{
private:
	string nombre;
	string telefono;

public:
	Espectador(string nombre, string telefono)
	{
		this->nombre = nombre;
		this->telefono = telefono;
	}

	void mostrar()
	{
		cout << " Nombre Cliente ; " << nombre << endl;
		cout << " Telf cliente  : " << telefono << endl;
	}

};