#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;
class PagoConDescuento : public Pago {
private:
	double descuento;
public:
	PagoConDescuento(double pagoOriginal) : Pago(pagoOriginal)
	{
		this->descuento = 0;
	}
	double calcularMontoFinal() override {
		descuento = pagoOriginal * 0.10;
		return pagoOriginal - descuento;
	}
	void mostrarInformacion() override {
		cout << "Monto Original: " << pagoOriginal << endl;
		cout << "Descuento (El 10%): " << descuento << endl;
		cout << "Total Pagado: " << calcularMontoFinal() << endl;
	}
};