#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pago
{
protected:
	float monto;
	
public:
	Pago(float monto)
		: monto(monto)
	{}
	virtual float calcularPago() = 0;
	virtual void mostrar() = 0;

	int getMonto()
	{
		return monto;
	}
	
};