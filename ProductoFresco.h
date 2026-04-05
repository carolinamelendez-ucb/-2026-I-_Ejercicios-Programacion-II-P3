#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;
class ProductoFresco : public Producto {
private:
	int diasRestVencimiento;
public:
	ProductoFresco(string nombre, float precio, int dias) : Producto(nombre, precio) {
		diasRestVencimiento = dias;
	}
	float calcularPrecioFinal() override {
		float descuento = 0.05 * (7 - diasRestVencimiento);
		if (descuento > 0.3) {
			descuento = 0.3;
		}
		return precioBase * (1 - descuento);
	}
};