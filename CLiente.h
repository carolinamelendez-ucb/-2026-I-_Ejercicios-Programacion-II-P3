#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
	string nombre;
	string ci;
public:
	Cliente(string nombre, string ci);
	void mostrar();
};

