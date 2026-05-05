#pragma once
#include <iostream>
#include <string>

using namespace std;

class Auto {
private:
	string nombre;
	string placa;
public:
	Auto(const string& nombre, const string& placa)
		: nombre(nombre), placa(placa)
	{
	}
};