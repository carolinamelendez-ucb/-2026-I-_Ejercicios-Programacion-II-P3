#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoComisionFija : public Pago {
private:
	double comision;
public:

	PagoComisionFija(double pagoOriginal)
		: Pago(pagoOriginal)
	{
		this->comision = 5;
	}

	double calcularMontoFinal() {
		return pagoOriginal + comision;
	}

	void mostrar() {

		cout << "Monto original: " << pagoOriginal << endl;
		cout << "Comsion: " << comision << endl;
		cout << "Total Pagado: " << calcularMontoFinal() << endl;
	}
};