#pragma once
#include <iostream>
#include <string>
using namespace std;
class Transporte {
protected:
	int numPlaca;
	float costoBase;
public:
	Transporte() = default;

	Transporte(int numPlaca, float costoBase)
		: numPlaca(numPlaca), costoBase(costoBase)
	{
	}

	virtual double calcularCosto(int distancia) = 0;

	virtual void mostrar() {
		cout << "Numero de placa: " << numPlaca << endl;
		cout << "Costo base:" <<costoBase << endl;
	}
	int getNumPlaca() {
		return numPlaca;
	}
};