#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;
class PagoComisionFija : public Pago {
private:
	double comision;
public:
	PagoComisionFija(double pagoOriginal) : Pago(pagoOriginal) 
	{
		this->comision = 5;
	}
	double calcularMontoFinal() override {
		return pagoOriginal + comision;
	}
	void mostrarInformacion() override {
		cout << "Monto Original: " << pagoOriginal << endl;
		cout << "Comision: " << comision << endl;
		cout << "Total Pagado: " << calcularMontoFinal() << endl;
	}
};