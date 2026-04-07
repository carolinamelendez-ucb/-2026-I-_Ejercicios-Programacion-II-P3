#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pago {
protected:
	string nombre;
	double monto;
public:
	Pago(const string& nombre, double monto)
		: nombre(nombre), monto(monto)
	{
	}

	double getMonto(){
		return monto;
	}

	virtual void mostrar() = 0;

	virtual double calcularMonto() = 0;


};