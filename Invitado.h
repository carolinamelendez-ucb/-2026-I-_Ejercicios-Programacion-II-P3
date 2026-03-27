#pragma once
#include <iostream>
#include <string>
using namespace std;
class Invitado
{
private:
	string nombre;
	int telefono;
public:
	Invitado(string nombre, int telefono)
	{
		this->nombre = nombre;
		this->telefono = telefono;
	}
};

