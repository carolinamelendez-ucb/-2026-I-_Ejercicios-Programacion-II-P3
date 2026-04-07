#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoComisionPorcentual : public Pago{

public:
	PagoComisionPorcentual(string nom,double mont)
	:Pago(nom,mont){ }

	double calcularPagoPorcentual() {
		double comision=monto * 0.03;
		return monto + comision;
	}

	void mostrar() {
		cout << "Cliente:" << nombre << endl;
		cout << "Monto Original: $" << monto << endl;
		cout << "Comision(3%): "<< comision<<endl;
		cout << "Total Pagado " << calcularPagoPorcentual() << endl;
	}

};