#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoComisionPorcentual: public Pago {
private:
	double comision;
public:

	PagoComisionPorcentual(double pagoOriginal)
		: Pago(pagoOriginal)
	{
		this->comision = 0;
	}

	double calcularMontoFinal() {
		comision = pagoOriginal * 0.03;
		return pagoOriginal + comision;
	}
	
	void mostrar() {

		cout << "Monto original: " << pagoOriginal << endl;
		cout << "Comision (3%): " << comision << endl;
		cout << "Total Pagado: " << calcularMontoFinal() << endl;
	}
};