#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoComisionPorcentual:public Pago
{
public:
	PagoComisionPorcentual(float monto)
		:Pago(monto)
	{}
	float calcularPago()
	{
		return monto + (monto * 0.03);
		//auqnur tambien podia ser 
		// monto*1.03
	}
	void mostrar()
	{
		float comision = monto * 0.03;
		cout << "Monto Original: " << monto << endl;
		cout << "Comision 3% " << comision << endl;
		cout << "Total pagado: " << calcularPago() << endl;

	}

};
