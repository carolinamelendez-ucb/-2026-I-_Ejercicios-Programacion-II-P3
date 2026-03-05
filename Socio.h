#pragma once
#include <iostream>
#include <string>
using namespace std;

class Socio
{
private:
	int ci;
	string nombre;
	int telefono;
public:
	Socio(int ci, string nombre, int telefono)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
	}
	string getNombre()
	{
		return nombre;
	}
	void mostrar()
	{
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telefono << endl;
	}
};