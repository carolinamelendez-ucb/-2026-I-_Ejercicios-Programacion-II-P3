#pragma once
#include <iostream>
using namespace std;

class Invitado {
private:
	string nombre;
	int telf;
public:
	Invitado()
	{
		nombre = "";
		telf = 0;
	}
	Invitado(string nombre, int telf)
	{
		this->nombre = nombre;
		this->telf = telf;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telf << endl;
	}
};