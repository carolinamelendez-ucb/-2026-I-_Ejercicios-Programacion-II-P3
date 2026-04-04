#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoPremium : public Producto {
private:
	double pesoKg;
public:
	ProductoPremium(string nom, double prB, double psKg)
	:Producto(nom, prB), pesoKg(psKg) {
	}

	double calcularPrecioFinal() {
		return (precioBase * 1.10 + (pesoKg * 2) * 1.15);
	}

	void mostrar() {
		cout << nombre <<" (Premium) - Precio Final: $"<<calcularPrecioFinal() << endl;
	}

};
