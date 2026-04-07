#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;
class PagoComisionPorcentual : public Pago {
private:
	double comision;
public:
	PagoComisionPorcentual(double pagoOriginal) : Pago(pagoOriginal)
	{
		this->comision = 0;
	}
	double calcularMontoFinal() override {
		comision = pagoOriginal * 0.03;
		return pagoOriginal + comision;
	}
	void mostrarInformacion() override {
		cout << "Monto Original: " << pagoOriginal << endl;
		cout << "Comision (El 3%): " << comision << endl;
		cout << "Total Pagado: " << calcularMontoFinal() << endl;
	}
};