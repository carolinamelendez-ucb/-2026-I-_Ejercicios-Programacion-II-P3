#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sala
{
private:
	int codigo;
	int filas, columas;
	int cantAsientos;
private:

public:

	Sala(int codigo, int filas, int columas, int cantAsientos)
		: codigo(codigo), filas(filas), columas(columas), cantAsientos(cantAsientos)
	{
	}
};

