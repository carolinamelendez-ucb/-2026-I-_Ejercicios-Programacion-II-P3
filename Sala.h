#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sala
{
private:
	int numeroPuerta;
	int numFilas;
	int numAsientosPorFila;
public:
	Sala(int numeroPuerta, int numFilas, int numAsientosPorFila)
		: numeroPuerta(numeroPuerta), numFilas(numFilas), numAsientosPorFila(numAsientosPorFila)
	{}
	void mostrar()
	{
		cout << "numFila: " << numFilas << endl;
		cout << "numAsiento: " << numAsientosPorFila << endl;
		cout << "num puerta: " << numeroPuerta << endl;
	}


	
};
