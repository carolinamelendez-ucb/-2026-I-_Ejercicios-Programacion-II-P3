#pragma once
#include <iostream>
#include <string>
using namespace std;
class Socio
{
private:
	int ci;
	string nombre;
	int telf;
public:
    Socio(int ci, const string& nombre, int telf)
		: ci(ci), nombre(nombre), telf(telf)
	{
	}
	Socio() 
	{
		this->ci = 0;
		this->nombre = "";
		this->telf = 0;
	}
	void mostrar()
	{
		cout << ci<<" " << nombre<<" " << telf;
	}
	string getNombre()
	{
		return nombre;
	}
	int getCi()
	{
		return ci;
	}
};

