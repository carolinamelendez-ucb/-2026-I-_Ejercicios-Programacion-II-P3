#pragma once
#include <iostream>
#include <string>
using namespace std;

class Espectador{
private:
	string nombre;
	int telefono;
public:

	Espectador (const string& nombre, int telefono)
		: nombre (nombre), telefono (telefono)
	{
	}
	void mostrar () const {
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telefono << endl;
	}

};
