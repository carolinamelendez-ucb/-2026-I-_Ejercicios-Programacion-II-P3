#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoPromocional : public Producto {
private:
	double descuentoPromocional;
	int cantidad;
public:
	ProductoPromocional(string nom, double prB, double desProm, int cant)
		:Producto(nom, prB), descuentoPromocional(desProm), cantidad(cant){
	}

	double calcularPrecioFinal() {
		return precioBase - descuentoPromocional - (cantidad > 5 ? (precioBase * 0.05) : 0);
	}

	void mostrar() {
		cout << nombre <<" (Promocional) - Precio Final: $"<< calcularPrecioFinal() << endl;
	}
};
