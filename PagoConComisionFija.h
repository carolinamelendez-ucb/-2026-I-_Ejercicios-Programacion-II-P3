#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;


class PagoComisionFija: public Pago{
private:
	double comiFija;
public:
	PagoComisionFija(string nom, double mont,double comfj)
		:Pago(nom, mont),comiFija(comfj) {

	}

	double calcularComisionFija() {
		return monto * comiFija;
	}

	void mostrar() {
		cout << "Cliente:" << nombre << endl;
		cout << "Monto Original: $" << monto << endl;
		cout << "Comision fija:"<<comiFija << endl;
		cout << "Total: $"<<calcularComisionFija()<<endl;
	}
};