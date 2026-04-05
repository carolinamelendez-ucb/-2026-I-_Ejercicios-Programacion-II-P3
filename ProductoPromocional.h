#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;
class ProductoPromocional : public Producto {
private:
	float descuentoFijo;
	int cantComprada;
public:
	ProductoPromocional(string nombre, float precio, float descuento, int cantidad) : Producto(nombre, precio) {
		descuentoFijo = descuento;
		cantComprada = cantidad;
	}
	float calcularPrecioFinal() override {
		float precio = precioBase - descuentoFijo;
		if (cantComprada > 5) {
			precio = precio - precioBase * 0.05;
		}
		return precio;
	}
};