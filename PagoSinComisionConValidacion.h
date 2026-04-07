#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;
class PagoSinComisionConValidacion : public Pago {
public:
	PagoSinComisionConValidacion(double pagoOriginal) : Pago(pagoOriginal)
	{

	}
	double calcularMontoFinal() override {
		if (pagoOriginal > 0) {
			return pagoOriginal;
		}
		else {
			return 0;
		}
	}
	void mostrarInformacion() override {
		cout << "Monto Original: " << pagoOriginal << endl;
		if (calcularMontoFinal() == pagoOriginal) {
			cout << "Se hizo el pago con exito" << endl;
		}
		else {
			cout << "Error, no se pudo procesar el pago" << endl;
		}
	}
};