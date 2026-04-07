#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class PagoSinComisionConValidacion: public Pago {
public:
	PagoSinComisionConValidacion(string nom, double mont)
		:Pago(nom, mont) {
	}

	double calcularSinComisionConValidacion() {
		if (monto > 0) {
			return monto;
		}
		else {
			cout << "El monto es invalido. No se puede procesar el pago" << endl;
		}
	}

	void mostrar() {
		cout<<"Cliente:"<< nombre << endl;
		cout<<"Monto Original: $"<< monto << endl;
		cout<<"Total: $"<<calcularSinComisionConValidacion() << endl;
	}

};