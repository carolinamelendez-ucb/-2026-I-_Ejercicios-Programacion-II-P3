#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pago {
protected: 
	double pagoOriginal;
public:

	Pago() = default;

	Pago(double pagoOriginal)
		: pagoOriginal(pagoOriginal)
	{
	}

	virtual double calcularMontoFinal() = 0;
	virtual void mostrar() = 0;


};