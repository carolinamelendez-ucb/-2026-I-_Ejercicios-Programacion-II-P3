#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoConComisionFija: public Pago
{
public:
	PagoConComisionFija(float monto)
		:Pago(monto)
	{}

	float calcularPago()
	{
		return monto + 5;
	}
	void mostrar()
	{
		cout << "Monto Original: " << monto << endl;
		cout << "Comision fija: 5 " << endl;
		cout << "Total pagado: " << calcularPago() << endl;
	}

};

