#pragma once
#include <iostream>
#include <string>

using namespace std;

class Socio
{
private:
	string nombre;
	int ci;
	int telefono;
public:
	Socio(){}
	Socio(string nombre, int ci, int telefono)
	{
		this->nombre = nombre;
		this->ci = ci;
		this->telefono=telefono;
	}

	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Ci: " << ci << endl;
		cout << "Telefono: " << telefono << endl;
	}

};

