#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;
class ProductoEnvasado : public Producto {
protected:
	float pesoEnKilos;
public:
	ProductoEnvasado(string nombre, float precio, float peso) : Producto(nombre, precio) {
		pesoEnKilos = peso;
	}
	float calcularPrecioFinal() override {
		return precioBase * 1.10 + (pesoEnKilos * 2);
	}
};