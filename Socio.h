#pragma once
#include <iostream>
#include <string>

using namespace std;

class Socio
{
private:
	int ci;
	string nombre;
	string telefono;
public:
	Socio(int ci, string nombre, string telefono);
	int getCi();
	string getNombre();
	string getTelefono();
	void mostrar();
};

