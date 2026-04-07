#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoConDescuento: public Pago  {
public:
	PagoConDescuento(string nom, double mont)
		:Pago(nom, mont) {
	}

	double calcularPagoConDescuento() {
		return monto * 0.10;
	}

	void mostrar() {
		cout <<"Cliente:" << nombre << endl;
		cout <<"Monto Original: $" << monto << endl;
		cout <<"Descuento(10%):" << endl;
		cout <<"Total: $"<<calcularPagoConDescuento() << endl;
	}

};