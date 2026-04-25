#pragma once
#include <iostream>
#include <string>

using namespace std;
class Sala
{
private:
	int numFilas;
	int numColumnas;
public:
	Sala(int numFilas, int numColumnas)
		: numFilas(numFilas), numColumnas(numColumnas)
	{
	}
	void mostar() {
		cout << "Numero de fila: " << numFilas << endl;
		cout << "Numero de columnas: " << numColumnas << endl;
	}
};

