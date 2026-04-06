#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoConDescuento : public Pago {
private:
	double descuento;
public:

	PagoConDescuento(double pagoOriginal)
		: Pago(pagoOriginal)
	{
		this->descuento = 0;
	}

	double calcularMontoFinal() {
		descuento = pagoOriginal * 0.10;
		return pagoOriginal - descuento;
	}

	void mostrar() {

		cout << "Monto original: " << pagoOriginal << endl;
		cout << "Descuento (10%): " << descuento << endl;
		cout << "Total Pagado: " << calcularMontoFinal() << endl;
	}
};