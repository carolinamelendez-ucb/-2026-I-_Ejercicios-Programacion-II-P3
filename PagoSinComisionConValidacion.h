#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoSinComisionConValidacion : public Pago {
	
public:

	PagoSinComisionConValidacion(double pagoOriginal)
		: Pago(pagoOriginal)
	{
	}

	double calcularMontoFinal() {
		if (pagoOriginal > 0) {
			return pagoOriginal;
		}
		else {
			return 0;
		}
	}

	void mostrar() {

		cout << "Monto original: " << pagoOriginal << endl;
		if (calcularMontoFinal() == pagoOriginal) {
			cout << "Se realizo el pago con exito" << endl;
		}
		else {
			cout << "Error, no se puedo procesar el pago" << endl;
		}
	}
};