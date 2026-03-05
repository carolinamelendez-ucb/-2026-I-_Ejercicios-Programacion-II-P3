#pragma once 
#include<iostream>
#include<string>
using namespace std;
class Socio {
private:
	int ci;
	string nombre;
	int telf;
public:
	Socio();
	Socio(int ci, string nombre, int telf)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->telf = telf;
	}
	int getCI() {
		return ci;
	}
	string getNombre() {
		return nombre;
	}
	int getTelf() {
		return telf;
	}
	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "CI: " << ci << endl;
		cout << "Telefono: " << telf << endl;
	}
};
