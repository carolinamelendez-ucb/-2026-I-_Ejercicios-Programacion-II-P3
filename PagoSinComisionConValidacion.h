#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoSinComisionConValidacion: public Pago
{
public:
	PagoSinComisionConValidacion(float monto)
		:Pago(monto)
	{}
	float calcularPago()
	{
		if (monto <= 0)
		{
			return 0;
		}
		return monto;
	}
	void mostrar() 
	{
		if (monto <= 0)
		{
			cout << "Error: monto invalido" << endl;
		}
		else
		{
			cout << "Monto original: " << monto << endl;
			cout << "Sin comision" << endl;
			cout << "Total pagado: " << calcularPago() << endl;
		}
	}

};



