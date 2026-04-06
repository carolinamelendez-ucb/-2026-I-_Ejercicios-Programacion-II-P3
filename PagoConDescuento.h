#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoConDescuento:public Pago
{
public:
	PagoConDescuento(float monto)
		:Pago(monto)
	{}
	
	float calcularPago()
	{
		return monto*0.90;
	}
	void mostrar()
	{
		float descuento = monto * 0.10;
		cout << "Monto Original: " << monto << endl;
		cout << "Descuento (10%) :" << descuento << endl;
		cout << "Total pagado" << calcularPago() << endl;

	}

};
